#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    input_t dense1_input[N_INPUT_1_1],
    result_t layer11_out[N_LAYER_5]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=dense1_input complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=dense1_input,layer11_out 
    #pragma HLS PIPELINE 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        // hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<weight2_t, 25>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 5>(b2, "b2.txt");
        nnet::load_weights_from_txt<threshold10_t, 5>(t10, "t10.txt");
        nnet::load_weights_from_txt<weight5_t, 25>(w5, "w5.txt");
        nnet::load_weights_from_txt<bias5_t, 5>(b5, "b5.txt");
        nnet::load_weights_from_txt<threshold11_t, 5>(t11, "t11.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    layer2_t layer2_out[N_LAYER_2];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
    nnet::dense<input_t, layer2_t, config2>(dense1_input, layer2_out, w2, b2); // dense1

    layer10_t layer10_out[N_LAYER_2];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    nnet::normalize_binary_tanh<layer2_t, config10>(layer2_out, layer10_out, t10); // bnbt_dense1_alpha

    layer5_t layer5_out[N_LAYER_5];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::dense<layer10_t, layer5_t, config5>(layer10_out, layer5_out, w5, b5); // dense2

    nnet::normalize_binary_tanh<layer5_t, config11>(layer5_out, layer11_out, t11); // bnbt_dense2_alpha

}
