open_project hls_prj
add_files ./s2mm.cpp
add_files ./s2mm.h
open_solution -reset -flow_target vitis "s2mm"
set_part {xcu50-fsvh2104-2-e}
create_clock -period 5 -name default
set_top s2mmTop
csynth_design
export_design -rtl verilog -format xo -output axi_s2mm.xo
exit