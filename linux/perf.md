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


Use perf
----

To record and report perf-events:
```
sudo perf record -e block:block_rq_issue -ag
# Press Ctrl + C to stop recording
sudo perf record
```

The resulting graph can be viewed interactively. Press `?` to see shortcuts.
