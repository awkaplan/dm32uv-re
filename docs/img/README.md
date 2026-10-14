# Screenshots

Every image here is a render of the emulated LCD, captured by this repo's own tooling and
regenerable from scratch. Nothing here is a photo of a radio or a capture of one unit's
configuration: the emulator boots the stock vendor firmware image with no codeplug attached, which
is why the standby screen reads "Null Ch." instead of channel names.

| file | what it shows |
|---|---|
| `stock-standby.png` | Stock firmware at the standby screen under `-M dm32` (no codeplug image attached). |
| `stock-menu.png` | The stock top-level menu, unmodified. |
| `snake-menu-category.png` | The same menu scrolled down, with **SNAKE** as a real 11th category. |
| `snake-sublist.png` | The SNAKE category's sub-list with its one item, `Play`. |
| `snake-gameplay.png` | The game running: snake (green), food (red), and the `K:xx` scan-code overlay. |
| `snake-walkthrough.png` | All of the above as one strip: menu, SNAKE entry, sub-list, three gameplay frames. |

## How they were made

One `qemu_run.py` session with a scripted key sequence (menu, Up to wrap onto SNAKE, OK, OK, then
four direction keys), then `render_frames.py` on the frames it dumped:

```sh
cd tools/src/dm32_patch_tools
python3 compose_qemu_image.py --patched ../../examples/snake/progmem_SNAKE_patched.bin \
    --out /tmp/snake_qemu.bin --iram-out
python3 qemu_run.py --image /tmp/snake_qemu.bin --iram /tmp/iram.bin --sram /tmp/sram.bin \
    --tag shots --rundir /tmp/shots --until-step 11 --settle-after 25 \
    --keyseq="-1:0:1:31:0:20;-1:0:1:17:20:120;2:11:1:17:60:400;2:7:1:17:60:400;2:7:1:17:60:600;2:11:1:18:150:500;2:8:1:20:150:500;2:11:1:17:150:500;2:8:1:18:150:500;2:10:1:17:150:900;2:10:1:17:150:900"
python3 render_frames.py --rundir /tmp/shots --single 102 --out ../../../docs/img/snake-gameplay.png
python3 render_frames.py --rundir /tmp/shots --frames 2,3,5,45,83,102 \
    --out ../../../docs/img/snake-walkthrough.png
```

Frame numbers come from the `F<n>:<nonblack>` token line `qemu_run.py` prints when it finishes;
pick the ones whose pixel counts match the screen you want (see `docs/qemu-workflow.md`'s
fingerprint list). The numbers above are from the 2026-10-10 run and will shift if the key script
or the patch changes.
