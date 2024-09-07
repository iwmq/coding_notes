Install perf
----

To install `perf` on Ubuntu:
```
sudo apt install linux-tools-generic-hwe-$(lsb_release -r -s)
```

To install `perf` on Manjaro:
```
sudo pacman -S perf
```


Allow Monitoring And Observability
----
To allow use of (almost) all events by all users, run:
```
sudo sysctl kernel.perf_event_paranoid=-1
```


Use perf
----

To record and report perf-events:
```
sudo perf record -e block:block_rq_issue -ag
# Press Ctrl + C to stop recording
sudo perf record
```

The resulting graph can be viewed interactively. Press `?` to see shortcuts.


To check TLB misses, run
```
perf stat -e dTLB-loads,dTLB-load-misses,iTLB-loads,iTLB-load-misses -p $PID
```

To list all TLB metrics, run
```
perf list TLB
```