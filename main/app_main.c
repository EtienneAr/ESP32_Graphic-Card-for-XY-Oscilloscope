#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "Main_app";

#include <math.h>
#define DRAWLINE(dist, angle_a, angle_b) XYPlotter_drawLine(127+dist*cos(angle_a*3.141592/180),127+dist*sin(angle_a*3.141592/180),127+dist*cos(angle_b*3.141592/180),127+dist*sin(angle_b*3.141592/180), pen)

esp_err_t app_main()
{
    XYPlotter_init(441000);
    esp_log_level_set("I2S", ESP_LOG_INFO);

    Pen_t pen = {.spacing = 1, .intensity = 2};

	GI_uid_t objects[5];
	int size = 0;

	for(int i = 0;i<5;i++) {
		objects[i] = XYPlotter_drawLine(0,0,0,255, pen);
	}

	while(1) {
		XYPlotter_delete(objects[0]);
		XYPlotter_delete(objects[1]);
		XYPlotter_delete(objects[2]);
		XYPlotter_delete(objects[3]);
		XYPlotter_delete(objects[4]);
		objects[0] = DRAWLINE(size, 0, 72);
		objects[1] = DRAWLINE(size, 72, 144);
		objects[2] = DRAWLINE(size, 144, 216);
		objects[3] = DRAWLINE(size, 216, 288);
		objects[4] = DRAWLINE(size, 288, 0);
		size = (size + 1)%127;
		vTaskDelay(1);
		ESP_LOGW(TAG, "Free heap memory : %d", xPortGetFreeHeapSize());
	}

    return ESP_OK;
}