#include "mm2s.h"

void mm2sTop(axiWord_t* in, axiDataStream_t &out_stream, int length){
    #pragma HLS INTERFACE mode=m_axi port=in offset=slave
    #pragma HLS INTERFACE mode=axis port=out_stream
    
    #pragma HLS INTERFACE s_axilite port=length
    #pragma HLS INTERFACE ap_none port=length
    #pragma HLS INTERFACE s_axilite port=return
    int i;
    for(i = 0; i < length; i++){
        #pragma HLS PIPELINE II=1
        axiDataBus bus;
        bus.data = in[i];
        bus.last = (i == (length-1))? 1: 0;
        out_stream.write(bus);
    }
}