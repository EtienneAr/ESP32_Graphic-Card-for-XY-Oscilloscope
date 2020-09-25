#include "DAC_XY_Plotter.h"

#if CONFIG_I2S_NUM_0
  #define I2S_PORT 0
#elif CONFIG_I2S_NUM_1
  #define I2S_PORT 1
#else
  #error No I2S port specified
#endif

void _i2s_init(uint32_t rate) {
	i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN,
        .sample_rate =  rate,
        .bits_per_sample = 16,
	    .communication_format = I2S_COMM_FORMAT_I2S_MSB, //?
	    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
	    .intr_alloc_flags = 0,
	    .dma_buf_count = 2,
	    .dma_buf_len = 1024,
	    .use_apll = false,
	 };
	 //install and start i2s driver
	 i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
	 
     i2s_set_pin(I2S_PORT, NULL);

     //init DAC pad
	 i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
}


void XYPlotter_init(uint32_t rate) {
	_i2s_init(rate);
}