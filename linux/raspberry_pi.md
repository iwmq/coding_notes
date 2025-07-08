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


Operation Systems
---
For my Raspberry Pi 4 and 5, I have tested various Linux distros on them.

The official `Raspberry OS` is stable and well supported, but its GUI looks very
plain.

`Manjaro ARM` is beautiful and comes with shining newest programming. However,
it stopped releasing new stable branch, only maitains unstable branch due to
lack of personnel.

`Twister OS` is my new finding, based on Debian, and with highly customizable
desktop themes (even Windows XP-style).

`Kali` is good too. But I don't need its tools.

`EndeavourOS ARM` is like `Manjaro ARM`. I failed to install as it requires good
Internet connection during installation.

I did try other options. `Ubuntu` is buggy for Raspberry Pi 5.