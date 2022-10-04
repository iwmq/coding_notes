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