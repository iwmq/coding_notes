rpi-clone
---
A shell script for cloning a running Raspberry Pi booted source disk (SD card or USB disk) to a destination disk which will be bootable.

It uses `rsync` to copy disk contents, and works for destination disk with smaller or larger size.


Rufus
---
There are may tools to create bootable SD cards for Raspberry Pi, including
the official `Raspberry Pi Imager`. However, I prefer `Rufus`, because it is
lightweight, reliable and simple. The only one drawback is it only supports
Windows.

Rufus URL: https://github.com/pbatard/rufus