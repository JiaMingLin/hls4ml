#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 5
#define N_LAYER_2 5
#define N_LAYER_2 5
#define N_LAYER_5 5
#define N_LAYER_5 5

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_uint<1> weight2_t;
typedef ap_int<2> bias2_t;
typedef ap_uint<1> layer2_index;
typedef ap_uint<1> layer10_t;
typedef ap_fixed<16,6> threshold10_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_uint<1> weight5_t;
typedef ap_int<2> bias5_t;
typedef ap_uint<1> layer5_index;
typedef ap_uint<1> result_t;
typedef ap_fixed<16,6> threshold11_t;

#endif
