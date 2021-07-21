# Parallel: Simple Vector Add (DPC++)

This project marks the beginning of my journey to learn Intel's oneAPI DPC++.

Linux distro "Pop!_OS 21.04"

cmake version 3.18.4

Intel(R) oneAPI DPC++/C++ Compiler 2021.3.0 (2021.3.0.20210619)

Ubuntu clang version 11.0.0-2 for non-parallel binary

## Steps

cd oneapi

./build.sh

./build/simple-vector-add

### Non-Parallel

cd non-parallel

./build.sh

./build/non-parallel-simple-vector-add

## History

dates: July 5 - July 7, 2021

duration: 4 hours

### Code from Another Developer

This code came directly from Intel.

[oneAPI Base Training Module](https://devcloud.intel.com/oneapi/get_started/baseTrainingModules/)

I modified the original Intel code to use std::vector instead of a C array.

Oleksandr Karaberov showed me how to initialize a numeric std::vector (or any container that supports iteration) using std::iota.
 
[Initialize with STL algorithms](https://stackoverflow.com/questions/17694579/use-stdfill-to-populate-vector-with-increasing-numbers)

Olivier Li showed me how to time code to microsecond accuracy for performance checking.

[Timing with Chrono](https://stackoverflow.com/questions/21856025/getting-an-accurate-execution-time-in-c-micro-seconds)

### Parallel

I placed this in my .bashrc file so the dpcpp compiler can be found.

> export ONEAPI_DIR="/opt/intel/oneapi"

> [ -s "$ONEAPI_DIR/setvars.sh" ] && \. "$ONEAPI_DIR/setvars.sh"  # initialize oneAPI environment

### Non-Parallel

The non-parallel version of the code has all the dpc++ extensions removed.

## Output

The dpcpp compiled parallel binary takes on average about 64000 seconds to run.

Whereas the clang compiled binary takes on average about 615 seconds to run, or 1% of the time taken by the oneAPI parallel program.

I attribute this horrible defeat of the parallel program to the lack of complexity in the calculation.  There is just not enough work to be done to reap any benefits of parallelization, but we still suffer the penalty of creating the parallel environment to execute the binary.

