Ignore PYTHONPATH
----
When Python imports a library, it will search `sys.path`, among which are
paths specified by the `PYTHONPATH` environment variable.

If libraries in `PYTHONPATH` conflict with what you want, there are two way
to get rid of them.

If working with Python interactive environment, add `-E`.

If working with a virtual environmet, we can modify its `bin/activate` script.

In the `deactivate` function, add:
```bash
    if [ -n "${_OLD_VIRTUAL_PYTHONHOME:-}" ] ; then
        PYTHONHOME="${_OLD_VIRTUAL_PYTHONHOME:-}"
        export PYTHONHOME
        unset _OLD_VIRTUAL_PYTHONHOME
    fi
```

and after the function, add:
```bash
if [ -n "${PYTHONPATH:-}" ] ; then
    _OLD_PYTHONPATH="${PYTHONPATH:-}"
    unset PYTHONPATH
fi
```