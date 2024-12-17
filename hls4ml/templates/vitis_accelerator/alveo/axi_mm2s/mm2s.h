#include <iostream>
#include<ap_int.h>
#include<hls_stream.h>

// hls-fpga-machine-learning insert bus_width

typedef ap_uint<BUS_WIDTH> axiWord_t;
typedef struct axiDataBus
{
    axiWord_t data;
    bool last;
}axiDataBus;
typedef hls::stream<axiDataBus> axiDataStream_t;

void mm2sTop(axiWord_t* in, axiDataStream_t &out_stream, int length);
