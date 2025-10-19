#!/bin/bash

source /mnt/applications/synopsys/2024-25/scripts/VC-STATIC_2024.09-SP1_RHELx86.sh

echo "waiting for 120s to exit ssh window, the program will run background"
sleep 1
echo "Program is starting"

SECONDS=0
success=0

for i in {1..10}
do
    echo "$i Times starting ./main"
    ./main
    
    DIR_NAME="cpp_$i"

    if [ ! -d "$DIR_NAME" ]; then
	    echo "creating new file folder $DIR_NAME"
	    mkdir -p "$DIR_NAME"
	    cd "$DIR_NAME"
	    mkdir run rtl cc cpp tcl
	    cd ..
    fi
    
    mv random_stl_program.cc cpp_$i/cc
    mv random_stl_program.cpp cpp_$i/cpp
    cp cc_gen.tcl cpp_$i/tcl
    cp random_stl_program_cpp.h cpp_$i/cpp
    cp random_stl_program_cc.h cpp_$i/cc
    cd cpp_$i
    cd cpp
    g++ random_stl_program.cpp -o program_$i
    ./program_$i
    mv rtl_program.sv ../rtl
    cd ..
    cd run
    vcf -fmode DPV -f ../tcl/cc_gen.tcl
    

    result=$(grep "*    success     check    spec.result(1) == impl.result(2)" "vcf.log")

    if [ -n "$result" ]; then
	    echo "No error case found in VC formal"
      cd ..
      cd ..
      #rm -r cpp_$i
      ((success++))

    else
	    echo "Find errors of fails in log file, please check!"
      cd ..
      cd ..
    fi

    echo "$i Times finishing..."




done

echo "Total success rate: $success / $i"
echo "Running time: $SECONDS s"
