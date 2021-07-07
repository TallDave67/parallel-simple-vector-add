//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================

#include <iostream>
#include <exception>

static const size_t N = 1000;

#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

// ############################################################
// work

void work() {
  std::cout << "Device : My laptop"
            << std::endl;
            
  // ### Step 1
  // Add input vector1
  std::vector<int> vector1(N);
  std::iota(vector1.begin(), vector1.end(), 1);
  //
  std::cout << "vector1  : ";
  for (const auto& elem: vector1) std::cout << elem << ' ';
  std::cout << std::endl;

  // ### Step 2 - Add another input vector2
  std::vector<int> vector2(N);
  std::generate(vector2.begin(), vector2.end(), [] {
      static int i = 0;
      return (++i * N);
  });  
  //
  std::cout << "vector2  : ";
  for (const auto& elem: vector2) std::cout << elem << ' ';
  std::cout << std::endl;

  // ### Step 3 - do nothing

  // ### Step 4 - loop across vectors
  int index = 0;
  while(index < N) {
    // ### Step 5 - do nothing

    // ### Step 6 - vector1 to accumulate from vector2
    vector1[index] += vector2[index];
    
    index++;
  }

  std::cout << "vector1 + vector2  : ";
  for (const auto& elem: vector1) std::cout << elem << ' ';
  std::cout << std::endl;
}

// ############################################################
// entry point for the program

int main() {  
  try {
    auto start = std::chrono::high_resolution_clock::now();
    work();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Elapsed microseconds : " << microseconds << std::endl;
  } catch (std::exception e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    std::terminate();
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
    std::terminate();
  }
}
