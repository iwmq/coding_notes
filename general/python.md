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

Run CPython Tests
----
This section describes how to build CPython from source and run tests.

```bash
    cd cpython && mkdir debug && cd debug
    ../configure --with-pydebug && make
    make test  TESTOPTS='-v test_cprofile
```

Accelerate Loops And NumPy
----
Using Numba, pure Python loops and NumPy functions can be compiled into native
machine code when executed for the first time, and subsequent executions will use
the cached native code.

Among Numba functions, the simplest and most useful one is the `njit` decorator.
I used it to gain more than 10X speedup for a `Traveling Salesman Problem (TSP)`
solver.

Although Numba likes loops and NumPy functions, it fails to compile Python's list
comprehension and NumPy arrays without a fixed data type.

A useful trick is to profile your algorithm via `cProfile`, find the slowest lines,
extract them into separate functions, the use Numba to accelerate these functions.

virtualenvwrapper
----

`virtualenvwrapper` is one of the best Python development tools I have even known.
It help you create and manage Python virtual environments in a very handy way.

Had I known this gorgeous tool before, many of ugly `xxx_ws/xxx_venv` folders
on my computers can be unnecessary.

See https://virtualenvwrapper.readthedocs.io/en/latest/.

Show output of containerized Python scripts
----

As Python buffers its output (both `stdout` and `stderr`), showing output (logs) of
a containerized Python script via `docker logs -f <container-name>` often displays
nothing. This could be fixed by invoking the script via `python -u <script>`.


pipx
----
A tool for installing system-wide isolated tools, extremely useful.
To install pipx:
```
pip install --user -U pipx
```

To install ipython and add Pillow as its dependency:
```
pipx install ipython
pipx inject ipython Pillow
```


poetry
----
A very useful too for managing Python projects, especially for development.

To install:
```
pipx install poetry
```


pdm
----
A modern Python package and dependency manager, similar to poetry.
Website: [pdm](https://pdm-project.org/latest/)