#!/bin/sh
# Validate specs/dts/dm32uv.dts.
#
#   specs/dts/validate.sh                  dtc only (must compile with no warnings)
#   specs/dts/validate.sh <bindings-dir>   also dt-validate against upstream schemas
#
# <bindings-dir> is Documentation/devicetree/bindings from a tagged Linux release (checked
# against v6.16), e.g. from
#   git clone --depth 1 --filter=blob:none --sparse -b v6.16 https://github.com/torvalds/linux.git
#   git -C linux sparse-checkout set Documentation/devicetree/bindings
# dt-validate / dt-mk-schema come from `pip install dtschema` (on PATH, or set DTSCHEMA_BIN to
# the directory holding them).
#
# dt-validate is run with -m, so every compatible without an upstream schema is reported. The
# expected reports are listed in EXPECTED below (the locally namespaced compatibles, and SPI
# master 3, which has no interrupt line in the datasheet's Table 30). Anything else fails.
set -eu

here=$(cd "$(dirname "$0")" && pwd)
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT

dtc -I dts -O dtb -o "$work/dm32uv.dtb" "$here/dm32uv.dts" 2>"$work/dtc.log" || {
	cat "$work/dtc.log"; echo "FAIL: dtc"; exit 1; }
if [ -s "$work/dtc.log" ]; then
	cat "$work/dtc.log"; echo "FAIL: dtc warnings"; exit 1
fi
echo "dtc: OK ($(wc -c <"$work/dm32uv.dtb" | tr -d ' ') bytes, no warnings)"

[ $# -ge 1 ] || exit 0
bindings=$1
bin=${DTSCHEMA_BIN:+$DTSCHEMA_BIN/}

"${bin}dt-mk-schema" -j -o "$work/schema.json" "$bindings" >"$work/mk.log" 2>&1 || {
	cat "$work/mk.log"; echo "FAIL: dt-mk-schema"; exit 1; }
"${bin}dt-validate" -m -s "$work/schema.json" "$work/dm32uv.dtb" >"$work/val.log" 2>&1 || true

cat >"$work/expected" <<'EOF'
/: failed to match any schema with compatible: ['baofeng,dm32uv', 'dahua,hr-c7000']
/cpus/cpu@0: failed to match any schema with compatible: ['csky,ck803s', 'csky,ck803']
/soc/flash-controller@3000000: failed to match any schema with compatible: ['dahua,hr-c7000-lcsfc']
/soc/syscon@11000000: failed to match any schema with compatible: ['dahua,hr-c7000-sysctl', 'syscon']
/soc/lcd-controller@12000000: failed to match any schema with compatible: ['dahua,hr-c7000-i8080']
/soc/lcd-controller@12000000/panel@0: failed to match any schema with compatible: ['dm32uv,lcd-panel']
/soc/watchdog@14010000: failed to match any schema with compatible: ['dahua,hr-c7000-wdt']
/soc/serial@14040000/gnss: failed to match any schema with compatible: ['dm32uv,atgm336h']
/soc/i2c@14080000/rtc@70: failed to match any schema with compatible: ['dahua,hr-c7000-rtc']
/soc/pwm@140c0000: failed to match any schema with compatible: ['dahua,hr-c7000-pwm']
/soc/adc@140d0000: failed to match any schema with compatible: ['dahua,hr-c7000-adc']
/soc/dac@140f0000: failed to match any schema with compatible: ['dahua,hr-c7000-dac']
/soc/spi-slave@14120000: failed to match any schema with compatible: ['dahua,hr-c7000-spi-slave']
/soc/spi-slave@14130000: failed to match any schema with compatible: ['dahua,hr-c7000-spi-slave']
/soc/spi-slave@14140000: failed to match any schema with compatible: ['dahua,hr-c7000-spi-slave']
spi@14150000 (snps,dw-apb-ssi): 'oneOf' conditional failed, one must be fixed:
'interrupts' is a required property
'interrupts-extended' is a required property
from schema $id: http://devicetree.org/schemas/spi/snps,dw-apb-ssi.yaml
/soc/spi@14150000/efuse@0: failed to match any schema with compatible: ['dahua,hr-c7000-efuse']
/soc/baseband@16000000: failed to match any schema with compatible: ['dahua,hr-c7000-baseband']
/soc/audio-codec@160009c0: failed to match any schema with compatible: ['dahua,hr-c7000-codec']
/soc/interrupt-controller@17000000: failed to match any schema with compatible: ['dahua,hr-c7000-pic']
/rf-frontend: failed to match any schema with compatible: ['dm32uv,rf-frontend']
/spi-0/transceiver@0: failed to match any schema with compatible: ['dm32uv,fd6818b']
/i2c-0/security@3d: failed to match any schema with compatible: ['neowine,alpu-mp']
EOF

# Normalise: drop the dtb path prefix and leading whitespace, de-duplicate.
sed -e 's#^[^ ]*dm32uv\.dtb: ##' -e 's/^[[:space:]]*//' "$work/val.log" | sort -u >"$work/got"
sort -u "$work/expected" >"$work/want"
if ! diff -u "$work/want" "$work/got" >"$work/diff"; then
	if grep -q '^+[^+]' "$work/diff"; then
		grep '^+[^+]' "$work/diff"
		echo "FAIL: unexpected dt-validate output (above)"; exit 1
	fi
	echo "note: some expected reports no longer appear (a binding may now exist):"
	grep '^-[^-]' "$work/diff" || true
fi
echo "dt-validate: OK ($(wc -l <"$work/want" | tr -d ' ') expected reports, nothing else)"
