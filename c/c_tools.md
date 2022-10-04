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