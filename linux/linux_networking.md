Networking Tools
----
The deprecated `net-tools` util set has been replaced by `ip` and `ss`. Now then two new utils are pre-installed
in most Linux distros.

- Use `ss` (standing for socket statistics) instead of `netstat`, for similar usage, with better output
- Use `ip neigh` or `ip n` instead of `arp`
- Use `ip addr` or `ip a` instead of `ifconfig`
- Use `ip route` or `ip r` instead of `route`

Besides, `iptables` has be replaced by its own developer with `nftables`.

To controlling NetworkManager on command line, use `nmcli` or `nmtui`.


Route Rules
----
A computer may be connected to more than one network interface cards (NICs),
for example, an ethernet port and a wireless access point. Traffics are then
routed via the NIC with lowest metric (higher priority).

To use a specific NIC, we can lower its metric with `ifmetric`:
```
sudo ifmetric <ifname> <metric>.
```

This tool is very lightweight, can can be installed:
```
sudo apt install ifmetric
```