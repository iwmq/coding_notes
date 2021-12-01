#!/usr/bin/env python3

"""
For Python, each thread has:
(1) Process id returned by os.getpid(),
(2) Native thread id of the operationg system
    (current_thread().native_id, available since Python3.8),
(3) Thread id of the Python runtime (current_thread().ident).
"""
import os
from threading import Thread, current_thread

def print_ids():
    cur_thread = current_thread()
    name = cur_thread.name
    pid = os.getpid()
    runtime_tid = cur_thread.ident
    native_tid = cur_thread.native_id
    print("Thread: {}, "
          "process id: {}, "
          "runtime thread id: {}, "
          "native thread id: {}"
          .format(name, pid, runtime_tid, native_tid))

def f():
    print_ids()


if __name__ == "__main__":
    print_ids()
    t = Thread(target=f, args=(), name="Child")
    t.start()
    t.join()
    """
    Output:
    Thread: MainThread, process id: 8989, runtime thread id: 139949255718720, native thread id: 8989
    Thread: Child, process id: 8989, runtime thread id: 139949244618496, native thread id: 8990
    """