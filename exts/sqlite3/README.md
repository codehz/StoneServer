sqlite3-cmake
=============

Simplest CMake script + full sqlite3 amalgamation distibution to build with different compilers

Build examples:

On Windows from Visual Studio command prompt
```
  cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=d:/libs
  nmake install
```

On Windows from Visual Studio IDE
```
  cmake -G "Visual Studio 12 Win64" -DCMAKE_INSTALL_PREFIX=d:/libs
  < open and build sqlite3.sln >
```

On Linux/FreeBSD without root access
```
  cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/student/libs
  make install
``` 