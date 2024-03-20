Search Path of Headers
----

A c/c++ compiler first does pre-process before compiling source files.
This pre-process is done via invoking a c preprocessor, to find and include
headers, to replace macros, etc.

The system search path of headers can be should via GCC's cpp or LLVM's clang-cpp.

For GCC, run `cpp -v -o /dev/null dev/null`.

For LLVM, run `clang-cpp-<version> -v -o /dev/null dev/null`.


Search Path of Libs
----

For GCC, run `ld --verbose | grep SEARCH_DIR | tr -s '; ' \\012`


SIMD Intrinsics
----
For SIMD intrinsics, the headers are provided by GCC or LLVM, and located in:
```
/usr/lib/llvm-18/lib/clang/18/include/immintrin.h
/usr/lib/gcc/x86_64-linux-gnu/12/include/immintrin.h
```