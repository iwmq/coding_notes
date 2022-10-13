Use ftrace
----

First, change to root user, and go to `/sys/kernel/tracing`
```
sudo su -
cd /sys/kernel/tracing
```

Then set tracing conditions. For example, trace `kernel_clone`:
```
echo function_graph > current_tracer
echo kernel_clone > set_ftrace_filter
echo kernel_clone > set_graph_function
echo 1 > tracing_on
```

The output can be read from `trace` or `trace_pipe`:
```
cat trace
```

Note: since v5.9, `_do_fork` is replaced by `kernel_clone`.