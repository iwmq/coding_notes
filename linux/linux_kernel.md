

Install Kernel With Mainline
----
To install latest Linux kernel, there is a convineint tool call `mainline`.

See github.com/bkw777/mainline.


Update Ubuntu 20.04 kernel
----
Ubuntu 20.04.5 comes with kernel 5.15, while some early versions stay on old kernel versions.
To upgrade to kernel 5.15, first installing `linux-generic-hwe-20.04`, then do normal dist-upgrade.


Customize Grub Menu
----
It is not wise to directly edit the automatically generated Grub configuration file `/boot/grub/grub.cfg`.
However, if we do want to adjust Grub menu, there is a package named `grub-customizer` to help.

NOTE: `grub-customizer` is not yet in the official repository of Ubuntu 22.04 due to some bug(s).


Interact With Grub
----
To see Grub menu, hold `Shift` key during booting. Once Grub menu appears, one
can press `e` to edit the current Grub configuration, or press `c` to bring up
Grub command line.

For a multi-boot computer, the Grub menu may show automatically for a few seconds,
as long as the latest installed OS is Linux.