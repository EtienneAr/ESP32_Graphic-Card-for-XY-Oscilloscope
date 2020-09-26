#include "DAC_XY_Plotter.h"
#include "DAC_XY_Plotter_priv.h"

#include "I2SManager.h"
#include "CircularLinkedList.h"
#include "GraphicItem.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "XYPlotter";
#include "esp_err.h"
#include "esp_log.h"

void XYPlotter_init(int rate) {
	I2SManager_init(rate);

	xTaskCreatePinnedToCore(XYPlotter_feeder, "XYPlotter-feeder", 2048, NULL, 10, NULL, 0);
}

void XYPlotter_feeder() {
	while(1) {
		GraphicItem_t *p_item = cll_next_item();
		if(p_item != NULL) {
			I2SManager_write_8bitLR(p_item->points, p_item->sizeof_points, NULL, portMAX_DELAY);
		} else {
			I2SManager_write_blank();
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}