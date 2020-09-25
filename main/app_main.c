#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/i2s.h"
#include "audio_example_file.h"


//i2s number
#define EXAMPLE_I2S_NUM           (0)
//i2s sample rate
#define EXAMPLE_I2S_SAMPLE_RATE   (220500)

/**
 * @brief I2S ADC/DAC mode init.
 */
void example_i2s_init()
{
	 i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN,
        .sample_rate =  EXAMPLE_I2S_SAMPLE_RATE,
        .bits_per_sample = 16,
	    .communication_format = I2S_COMM_FORMAT_I2S_MSB, //?
	    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
	    .intr_alloc_flags = 0,
	    .dma_buf_count = 2,
	    .dma_buf_len = 1024,
	    .use_apll = false,
	 };
	 //install and start i2s driver
	 i2s_driver_install(EXAMPLE_I2S_NUM, &i2s_config, 0, NULL);
	 
     i2s_set_pin(EXAMPLE_I2S_NUM, NULL);

     //init DAC pad
	 i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
}

void example_i2s_adc_dac(void*arg)
{
    size_t bytes_written;
    while (1) {

        i2s_write(EXAMPLE_I2S_NUM, audio_table, sizeof(audio_table), &bytes_written, portMAX_DELAY);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

esp_err_t app_main()
{
    example_i2s_init();
    esp_log_level_set("I2S", ESP_LOG_INFO);
    xTaskCreate(example_i2s_adc_dac, "example_i2s_adc_dac", 1024 * 2, NULL, 5, NULL);
    return ESP_OK;
}


