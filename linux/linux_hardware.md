Monitor Current CPU Frequencies
----

There following command extract current CPU frequencies every two seconds:
```
watch "grep 'cpu MHz' /proc/cpuinfo"
```

Almost all articles/answers on the Internet just say how to check static CPU frequencies.


Limit CPU Frequencies
----

For Ubuntu, there is an intuitive application, `cpupower-gui` to set min and max frequencies.

To install:
```
sudo apt install cpupower-gui
```


Decode Hardware Information
----
To check information of memory, run `sudo dmidecode --type memory`.

This command will list all hardware types if not specified a type.

All types are: bios, system, baseboard, chassis, processor, memory, cache, connector slot.