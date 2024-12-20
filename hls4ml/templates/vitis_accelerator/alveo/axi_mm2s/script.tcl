open_project hls_prj
add_files ./mm2s.cpp
add_files ./mm2s.h
open_solution -reset -flow_target vitis "mm2s"
set_part {xcu50-fsvh2104-2-e}
create_clock -period 5 -name default
set_top mm2sTop
csynth_design
export_design -rtl verilog -format xo -output axi_mm2s.xo
exit