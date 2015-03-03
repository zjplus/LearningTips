onerror {exit -code 1}
vlib work
vlog -work work FrequencyDivision.vo
vlog -work work Waveform.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiv_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate_ver -L altera_lnsim_ver work.FrequencyDivision097_vlg_vec_tst -voptargs="+acc"
vcd file -direction FrequencyDivision.msim.vcd
vcd add -internal FrequencyDivision097_vlg_vec_tst/*
vcd add -internal FrequencyDivision097_vlg_vec_tst/i1/*
run -all
quit -f
