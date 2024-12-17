#include "myproject_axi_stream.h"

void myproject_axi_stream(input_stream_t &in, output_stream_t &out) {

    #pragma HLS INTERFACE axis port=in
    #pragma HLS INTERFACE axis port=out
    #pragma HLS INTERFACE ap_ctrl_none port=return

    #pragma HLS DATAFLOW disable_start_propagation
    bool is_last = false;
    input_t in_local[N_IN];
    result_t out_local[N_OUT];

    if (!in.empty()) {
        axiInBus bus = in.read();
        for (unsigned i = 0; i < N_IN; i++) {
            in_local[i] = bus.range(IN_DATA_WIDTH*(i+1)-1, IN_DATA_WIDTH*i);
        }
    
        myproject(in_local, out_local);

        axiOutBus out_bus;
        for (unsigned i = 0; i < N_OUT; i++) {
            out_bus.range(OUT_DATA_WIDTH*(i+1)-1, OUT_DATA_WIDTH*i) = out_local[i];
        }
        out.write(out_bus);
    
    }
}