#ifndef MYPROJECT_AXI_H_
#define MYPROJECT_AXI_H_

#include <iostream>
#include <ap_int.h>
// hls-fpga-machine-learning insert include

// hls-fpga-machine-learning insert definitions

static const unsigned IN_DATA_WIDTH = T_in::width;
static const unsigned OUT_DATA_WIDTH = T_out::width;
// a data bus
#define IN_BUS_WIDTH N_IN*IN_DATA_WIDTH
typedef ap_uint<IN_BUS_WIDTH> axiInBus;
#define OUT_BUS_WIDTH N_OUT*OUT_DATA_WIDTH
typedef ap_uint<OUT_BUS_WIDTH> axiOutBus;

// stream of words
typedef hls::stream<axiInBus> input_stream_t;
typedef hls::stream<axiOutBus> output_stream_t;

void myproject_axi_stream(input_stream_t &in, output_stream_t &out);
#endif
