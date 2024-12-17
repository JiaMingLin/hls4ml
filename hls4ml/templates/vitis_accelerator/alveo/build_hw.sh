#!/bin/bash

PLATFORM=xilinx_u50_gen3x16_xdma_5_202210_1

XO_PATH = xo/axi_mm2s.xo xo/myproject_axi_stream.xo xo/axi_s2mm.xo

v++ -l -g -t hw --platform ${PLATFORM} --config config.cfg ${XO_PATH} -o ./myproject.xclbin

# --debug.chipscope s2mm --debug.protocol all --profile.data all:all:all 
# --report_level 2 --profile.trace_memory HBM[31]