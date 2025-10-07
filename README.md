# VicvecFuzz

## Overview
VicvecFuzz generates random C++ programs that test STL containers and then derives matching SystemVerilog and VC Formal setups to check the equivalence checker.

## Building the Generator
1. Ensure a C++17-capable compiler is available (e.g., GCC 11+).
2. Build the generator executable:
   g++ *.cpp -o main
3. Allow execution permisssion:
   chmod +x ./compile_loop.sh
4. Run the script:
   ./compile_loop.sh

