rpi-clone
---
A shell script for cloning a running Raspberry Pi booted source disk (SD card or USB disk) to a destination disk which will be bootable.

It uses `rsync` to copy disk contents, and works for destination disk with smaller or larger size.