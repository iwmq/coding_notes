Hardware
----
To play with Linux kernel, I bought a mini PC with footprint as small as 72x72x44.5mm.
It has a quad-core Intel Celeron N5105 processor.


Dependencies
----
To build kernel, some system dependecies are needed:
```
sudo apt install build-essential make flex bison libssl-dev libelf-dev dwarves
```


Configuration
----
To make things simple, just copy one existing configuration file from `/boot`:
```
copy /boot/config-5.15.0-25-generic .config
```


Buiding and intalling
----
After configuration, just run the following commands:
```
make -j4
sudo make INSTALL_MOD_STRIP=1 modules_install
sudo make install
```


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


Some errors
----
The configuration provided by Ubuntu has some certification steps enabled.
Because I have no such keys on the computer, the building process will stop,
showing the error:
```
No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'.  Stop.
```
To resolve this, change the values of the following options to empty:
- CONFIG_SYSTEM_REVOCATION_KEYS
- CONFIG_SYSTEM_TRUSTED_KEYS

If `dwarves` is not installed, the following error will occur:
```
BTF: .tmp_vmlinux.btf: pahole (pahole) is not available
Failed to generate BTF for vmlinux
Try to disable CONFIG_DEBUG_INFO_BTF
make: *** [Makefile:1208: vmlinux] Error 1
```

If `INSTALL_MOD_STRIP=1` is not specified when installing modules, the generated
RAM disk file (`initrd.img`) will be too big (478 M for kernel 5.15.57), so the
bootloader grub will fail to load it in RAM.