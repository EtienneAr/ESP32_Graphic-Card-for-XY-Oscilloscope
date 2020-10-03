#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "Main_app";

#include <math.h>
#define DRAWLINE(dist, angle_a, angle_b) XYPlotter_drawLine(127+dist*cos(angle_a*3.141592/180.),127+dist*sin(angle_a*3.141592/180.),127+dist*cos(angle_b*3.141592/180.),127+dist*sin(angle_b*3.141592/180.), pen)

esp_err_t app_main()
{
    XYPlotter_init(441000);
    esp_log_level_set("I2S", ESP_LOG_INFO);

    Pen_t pen = {.spacing = 1, .intensity = 2};

    /*
	XYPlotter_drawLine(0, 0, 255, 255, pen);
	XYPlotter_drawLine(255, 0, 0, 0, pen);
	XYPlotter_drawLine(255, 255, 255, 0, pen);
	XYPlotter_drawLine(0, 255, 255, 255, pen);
    XYPlotter_drawLine(0, 0, 0, 255, pen);
	*/

    
	XYPlotter_drawLine(255-17, 13, 255-80, 18, pen);
	XYPlotter_drawLine(255-80, 18, 255-79, 59, pen);
	XYPlotter_drawLine(255-79, 59, 255-53, 58, pen);
	XYPlotter_drawLine(255-53, 58, 255-44, 16, pen);
	XYPlotter_drawLine(255-44, 16, 255-40, 62, pen);
	XYPlotter_drawLine(255-40, 62, 255-11, 59, pen);
	XYPlotter_drawLine(255-11, 59, 255-16, 15, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-79, 73, 255-49, 72, pen);
	XYPlotter_drawLine(255-49, 72, 255-49, 96, pen);
	XYPlotter_drawLine(255-49, 96, 255-76, 95, pen);
	XYPlotter_drawLine(255-76, 95, 255-78, 73, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-76, 103, 255-48, 103, pen);
	XYPlotter_drawLine(255-48, 103, 255-71, 112, pen);
	XYPlotter_drawLine(255-71, 112, 255-48, 115, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-48, 121, 255-49, 148, pen);
	XYPlotter_drawLine(255-49, 148, 255-49, 133, pen);
	XYPlotter_drawLine(255-49, 133, 255-75, 135, pen);
	XYPlotter_drawLine(255-75, 135, 255-73, 121, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-49, 154, 255-77, 151, pen);
	XYPlotter_drawLine(255-77, 151, 255-75, 168, pen);
	XYPlotter_drawLine(255-75, 168, 255-50, 172, pen);
	XYPlotter_drawLine(255-50, 172, 255-49, 154, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-49, 175, 255-73, 176, pen);
	XYPlotter_drawLine(255-73, 176, 255-74, 191, pen);
	XYPlotter_drawLine(255-74, 191, 255-48, 191, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-49, 199, 255-75, 200, pen);
	XYPlotter_drawLine(255-75, 200, 255-50, 199, pen);
	XYPlotter_drawLine(255-50, 199, 255-50, 219, pen);
	XYPlotter_drawLine(255-50, 219, 255-62, 218, pen);
	XYPlotter_drawLine(255-62, 218, 255-61, 199, pen);
	XYPlotter_drawLine(255-61, 199, 255-75, 219, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-150, 11, 255-99, 30, pen);
	XYPlotter_drawLine(255-99, 30, 255-132, 40, pen);
	XYPlotter_drawLine(255-132, 40, 255-108, 81, pen);
	XYPlotter_drawLine(255-108, 81, 255-166, 65, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-170, 77, 255-111, 100, pen);
	XYPlotter_drawLine(255-111, 100, 255-123, 135, pen);
	XYPlotter_drawLine(255-123, 135, 255-177, 106, pen);
	XYPlotter_drawLine(255-177, 106, 255-170, 77, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-179, 120, 255-126, 143, pen);
	XYPlotter_drawLine(255-126, 143, 255-186, 139, pen);
	XYPlotter_drawLine(255-186, 139, 255-137, 175, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-194, 155, 255-141, 191, pen);
	XYPlotter_drawLine(255-141, 191, 255-169, 209, pen);
	XYPlotter_drawLine(255-169, 209, 255-197, 184, pen);
	XYPlotter_drawLine(255-197, 184, 255-194, 155, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(255-229, 230, 255-209, 191, pen);
	XYPlotter_drawLine(255-209, 191, 255-156, 229, pen);
	XYPlotter_drawLine(255-156, 229, 255-172, 254, pen);
	XYPlotter_drawLine(255-181, 212, 255-196, 242, pen);
	

    return ESP_OK;
}