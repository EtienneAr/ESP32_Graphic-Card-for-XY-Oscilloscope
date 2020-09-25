#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "audio_example_file.h"

#include "include/DAC_XY_Plotter.h"

void example_i2s_adc_dac(void*arg)
{
    size_t bytes_written;
    while (1) {

        i2s_write(0, audio_table, sizeof(audio_table), &bytes_written, portMAX_DELAY);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

esp_err_t app_main()
{
    XYPlotter_init(44100);
    esp_log_level_set("I2S", ESP_LOG_INFO);
    xTaskCreate(example_i2s_adc_dac, "example_i2s_adc_dac", 1024 * 2, NULL, 5, NULL);
    return ESP_OK;
}


