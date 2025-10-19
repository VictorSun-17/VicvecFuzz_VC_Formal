# VicvecFuzz

## Overview
VicvecFuzz generates random C++ programs that test STL containers and then derives matching SystemVerilog and VC Formal setups to check the equivalence checker.

## Building the Generator
1. Ensure a C++17-capable compiler is available (e.g., GCC 11+).
2. Build the generator executable:
   g++ -std=c++17 *.cpp -o main
3. Allow execution permisssion:
   chmod +x ./compile_loop.sh

## Running the Generator
1. Once built, you can directly run the generator to produce a single random testcase:
   ./main

## Using compile_loop.sh
The provided ./compile_loop.sh script is a convenience wrapper that repeatedly builds and checks new random testcases.
   ./compile_loop.sh
⚠️ Important:
The script currently assumes a hardcoded path to a VC Formal installation. You will likely need to edit compile_loop.sh to point to the VC Formal binary on your system. Consider the script as a starting point for automation rather than a universal solution.
