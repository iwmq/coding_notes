To enable debug information in the resulting executable, run:
```
make CFLAGS="-DRAX_DEBUG_MSG -Og -gdwarf-5 -Wall"
```
or:
```
make CFLAGS="-DRAX_DEBUG_MSG -Og -g3 -Wall"
```

NOTE: if multiple `-g` options are specified, only the last one is effective.

Now run redis server:
```
./src/redis-server ./redis.conf --port 6380
```

Remember the PID from the output.

Then attach gdb to the process:
```
sudo gdb ./src/redis-server -p <pid>
```

The following are commands running in gdb.
```
set $myrax = raxNew()

call raxShow($myrax)

call raxInsert($myrax, "foo", 3, "and will do it", null)

call raxInsert($myrax, "name", 4, "doge", null)

print $myrax.numele 

set $mynode = (raxNode *)raxFind($myrax, "foo", 3)

print $mynode.iskey 

print $mynode.data

info function -n rax
```

Another example:
```
set $c = createClient(NULL)
call $c->querybuf = sdsnew("xadd s * name ted")
call $c->qb_pos = sdslen($c->querybuf - 1)
call processInputBuffer($c)
call $c->cmd = lookupCommandOrOriginal($c->argv,$c->argc)
print $c->cmd->fullname
call $c->cmd->proc($c)
```