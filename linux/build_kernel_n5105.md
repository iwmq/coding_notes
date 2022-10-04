Hardware
----
The following results are collected from a mini PC with footprint as small as 72x72x44.5mm.
It has a quad-core Intel Celeron N5105 processor.

The mini PC is running on Linux Mint 21 XFCE Edition.


Kernel image size:
----
The genrated RAM disk files, named `initrd.img-<version>`, resides on `/boot`,
and have dramatically various sizes:
- For `5.15.57` kernel without modules stripping: 478 M
- For `5.15.57` kernel with modules stripping: 55 M
- For `5.15.58` kernel with modules stripping: 60 M


Time used
----
Following are times to build and install `5.15.58` kernel, respectively:
- Building kernel (`time make -j4`): 99 minutes and 22 seconds
- Installing modules (`time sudo make INSTALL_MOD_STRIP=1 modules_install`): 3 minutes and 7 seconds
- Installing kernel (`time sudo make install`): 15 seconds