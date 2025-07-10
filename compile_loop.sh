#!/bin/bash

source /mnt/applications/synopsys/2024-25/scripts/VC-STATIC_2024.09-SP1_RHELx86.sh


for i in {1..5}
do
    echo "$i Times doing ./main"
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
    cd cpp_$i
    cd cpp
    g++ random_stl_program.cpp -o program_$i
    ./program_$i
    mv rtl_program.sv ../rtl
    cd ..
    cd run
    vcf -fmode DPV -f ../tcl/cc_gen.tcl
    
    cd ..
    cd ..





done
