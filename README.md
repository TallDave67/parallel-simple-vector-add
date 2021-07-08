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

[OneAPI Base Training Module](https://devcloud.intel.com/oneapi/get_started/baseTrainingModules/)

## Parellel and Non-Parallel

I modified the original Intel code to use std::vector instead of a C array.

Then I created a non-parallel version of the code that has all the dpc++ extensions removed.

## Output

The dpcpp compiled parallel binary takes on average about 64000 seconds to run.

Whereas the clang compiled binary takes on average about 615 seconds to run, or 1% of the time taken by the OneAPI parallel program.

I attribute this horrible defeat of the parallel program to the lack of complexity in the calculation.  There is just not enough work to be done to reap any benefits of parallelization, but we still suffer the penalty of creating the parallel environment to execute the binary.

