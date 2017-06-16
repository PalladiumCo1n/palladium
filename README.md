http://palladium.greyblockgames.com/

## Building PalladiumCoin 

### On *nix

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.55 or later.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/
* Alternatively, it may be possible to install them using a package manager.

To build, change to a directory where this file is located, and run `make`. The resulting executables can be found in `build/release/src`.

**Ubuntu 16.04 Build:**

* Execute the following command to get everything you need in order to setup an environment *
`sudo apt-get install build-essential git cmake libboost1.58-all-dev`
* Execute the following command to copy the repository *
`git clone https://github.com/PalladiumCo1n/palladium.git`
* Execute the following command to get into the directory with copied repository *
`cd palladium`
* Execute the following command to build *

```make -j `nproc` ```

### On Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55 or later. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run theas commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```

And then do Build.
Good luck!
