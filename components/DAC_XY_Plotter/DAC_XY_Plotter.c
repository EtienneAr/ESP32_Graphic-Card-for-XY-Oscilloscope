#include "DAC_XY_Plotter.h"
#include "DAC_XY_Plotter_priv.h"

#include "I2SManager.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "XYPlotter";
#include "esp_err.h"
#include "esp_log.h"


#include "audio_example_file.h"

void XYPlotter_init(int rate) {
	I2SManager_init(rate);

	xTaskCreatePinnedToCore(XYPlotter_feeder, "XYPlotter-feeder", 2048, NULL, 10, NULL, 0);
}


void XYPlotter_feeder() {
	size_t bytes_written;
	while(1) {
		I2SManager_write_8bitLR(audio_table, sizeof(audio_table), &bytes_written, portMAX_DELAY);
		vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}