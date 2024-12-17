open_project hls_prj
add_files ./myproject_axi_stream.cpp -cflags "-std=c++0x -I../"
add_files ../myproject.cpp -cflags "-std=c++0x"
add_files -tb ../weights
open_solution -reset -flow_target vitis "myproject_axi_stream"
set_part {xcu50-fsvh2104-2-e}
create_clock -period 5 -name default
set_top myproject_axi_stream
csynth_design
export_design -rtl verilog -format xo -output myproject_axi_stream.xo
exit
