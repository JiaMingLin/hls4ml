#include<ap_int.h>
#include<hls_stream.h>

// hls-fpga-machine-learning insert bus_width

typedef ap_uint<BUS_WIDTH> axiWord_t;

typedef struct axiDataBus
{
    axiWord_t data;
    bool last;
} axiDataBus;

typedef hls::stream<axiDataBus> axiDataStream_t;

void s2mmTop(axiDataStream_t &input, axiWord_t* output);