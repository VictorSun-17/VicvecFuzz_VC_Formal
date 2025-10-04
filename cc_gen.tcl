set _hector_comp_use_new_flow true
set _hector_softfloat_version custom
set _hector_sym_maxiter_allgood 4096

proc compile_spec {} {
    create_design -name spec -top hector_wrapper
    cppan -m64 -Iinclude -DCHECKFP -DDPV_MAX_VECTOR_SIZE=4096 ../cc/random_stl_program.cc 
    compile_design spec
}

proc compile_impl {} {
    create_design -name impl -top add -clock clock -reset resetN -negReset
    vcs -sverilog ../rtl/rtl_program.sv
    
    compile_design impl
}

proc make {} {
    compile_spec
    compile_impl
    compose
}

proc ual {} {
    map_by_name -inputs -specphase 1 -implphase 1
    lemma check = spec.result(1) == impl.result(2)
}

proc run_main {} {
    set_user_assumes_lemmas_procedure "ual"
    solveNB p
    proofwait
}

make
run_main
listproof
exit