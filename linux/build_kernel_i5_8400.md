Hardware
----
The following results are collected from a home-made PC with standard housing.

It has a hexa-core Intel Core i5-8400 processor, with base frequency 2.8 GHz
and boost frequency 4 GHz.

The PC is running on Linux Mint 21 XFCE Edition.


Time used
----
Following are times to build and install `6.0` kernel, respectively:
- Building kernel (`time make -j6`): 39 minutes and 49 seconds
- Installing modules (`time sudo make INSTALL_MOD_STRIP=1 modules_install`): 1 minutes and 34 seconds
- Installing kernel (`time sudo make install`): 30 seconds