#include "I2SManager.h"

#include <string.h>
#include "driver/i2s.h"

#include "esp_err.h"
#include "esp_log.h"

static const char* TAG = "I2S-Manager";

#define I2S_PORT ((i2s_port_t) 0)
#define I2S_BUF_LEN 1024
#define I2S_BUF_COUNT 4

#define CONVERSION_CHUNK_SIZE 1024

#define min(x,y) ((x)<(y) ? (x) : (y))

void I2SManager_init(int rate) {
	ESP_LOGI(TAG, "init I2S");
	
	i2s_config_t i2s_config = {
        .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
        .sample_rate =  rate,
        .bits_per_sample = 16,
	    .communication_format = I2S_COMM_FORMAT_I2S_MSB, //?
	    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
	    .intr_alloc_flags = 0,
	    .dma_buf_count = I2S_BUF_COUNT,
	    .dma_buf_len = I2S_BUF_LEN,
	    .use_apll = false,
	 };
	 //install and start i2s driver
	 ESP_ERROR_CHECK(i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL));
	 
     ESP_ERROR_CHECK(i2s_set_pin(I2S_PORT, NULL));

     //init DAC pad
	 ESP_ERROR_CHECK(i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN));

}

void I2SManager_write_16bitLR(const void *src, size_t size, size_t *bytes_written, TickType_t ticks_to_wait) {
	ESP_ERROR_CHECK(i2s_write(I2S_PORT, src, size, bytes_written, ticks_to_wait));
}

void I2SManager_write_8bitLR(const void *src, size_t size, size_t *bytes_written, TickType_t ticks_to_wait) {
    uint8_t *buff_16bitLR = malloc(2*CONVERSION_CHUNK_SIZE);
    *bytes_written = 0;

    if(buff_16bitLR == NULL) {
    	ESP_LOGE(TAG, "impossible to alloc conversion chunk !");
    	return;
    }

    for(int offset=0;offset<size;offset+=CONVERSION_CHUNK_SIZE) {
    	int chunk_size = min(size, CONVERSION_CHUNK_SIZE);
	    for (int i = 0; i < chunk_size; i++) {
	        buff_16bitLR[2*i] = 0;
	        buff_16bitLR[2*i+1] = ((uint8_t *) src)[offset + i];
	    }
	   	size_t chunkwritten;
	    I2SManager_write_16bitLR(buff_16bitLR, chunk_size*2, &chunkwritten, ticks_to_wait);
	    bytes_written += chunkwritten;
    }

    free(buff_16bitLR);
    //Converts to 8bits
    *bytes_written /= 2;
}