
TPyBoard
----
TPyBoard v102 (STM32F405RG) is a clone of PyBoard v1, with MicroPython 1.9.3.

To flash a newer MicroPython version:
1. Download firmware, say PYBV10-20231005-v1.21.0.dfu.
2. Install dfu-util: sudo apt intall dfu-util.
3. Connect DFU and 3v3 pins via a jumper.
4. Plug the board to the computer via USB.
5. Go to the board's shell: sudo screen /dev/ttyACM0.
6. On te board shell: run:
```
import machine
machine.bootloader()
```
7. On the host computer, run:
```
sudo dfu-util  --alt 0 -D PYBV10-20231005-v1.21.0.dfu
```
