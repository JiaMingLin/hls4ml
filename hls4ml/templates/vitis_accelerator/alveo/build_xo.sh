#!/bin/bash

CURR_DIR=$(pwd)

mkdir -p ${CURR_DIR}/xo

pushd ./hls4ml_prj/firmware/axi_stream/
rm -rf hls_proj *.xo *.log
vitis_hls -f script.tcl
cp *.xo ${CURR_DIR}/xo
popd

pushd ./hls4ml_prj/firmware/axi_mm2s/
rm -rf hls_proj *.xo *.log
vitis_hls -f script.tcl 
cp *.xo ${CURR_DIR}/xo
popd

pushd ./hls4ml_prj/firmware/axi_s2mm/
rm -rf hls_proj *.xo *.log
vitis_hls -f script.tcl
cp *.xo ${CURR_DIR}/xo
popd