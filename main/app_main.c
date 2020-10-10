#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "Main_app";

#include <math.h>
#define DRAWLINE(dist, angle_a, angle_b) XYPlotter_drawLine(127+dist*cos(angle_a*3.141592/180.),127+dist*sin(angle_a*3.141592/180.),127+dist*cos(angle_b*3.141592/180.),127+dist*sin(angle_b*3.141592/180.), pen)

#define MIN_MAX_0_255(x) ((x < 0) ? 0 : ((x > 255) ? 255 : x))

esp_err_t app_main()
{
    XYPlotter_init(441000);
    esp_log_level_set("I2S", ESP_LOG_INFO);

    Pen_t pen = {.spacing = 1, .intensity = 1};

    /*
	XYPlotter_drawLine(0, 0, 255, 255, pen);
	XYPlotter_drawLine(255, 0, 0, 0, pen);
	XYPlotter_drawLine(255, 255, 255, 0, pen);
	XYPlotter_drawLine(0, 255, 255, 255, pen);
    XYPlotter_drawLine(0, 0, 0, 255, pen);
	*/

    
	XYPlotter_drawLine(13, 255-17, 18, 255-80, pen);
	XYPlotter_drawLine(18, 255-80, 59, 255-79, pen);
	XYPlotter_drawLine(59, 255-79, 58, 255-53, pen);
	XYPlotter_drawLine(58, 255-53, 16, 255-44, pen);
	XYPlotter_drawLine(16, 255-44, 62, 255-40, pen);
	XYPlotter_drawLine(62, 255-40, 59, 255-11, pen);
	XYPlotter_drawLine(59, 255-11, 15, 255-16, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(73, 255-79, 72, 255-49, pen);
	XYPlotter_drawLine(72, 255-49, 96, 255-49, pen);
	XYPlotter_drawLine(96, 255-49, 95, 255-76, pen);
	XYPlotter_drawLine(95, 255-76, 73, 255-78, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(103, 255-76, 103, 255-48, pen);
	XYPlotter_drawLine(103, 255-48, 112, 255-71, pen);
	XYPlotter_drawLine(112, 255-71, 115, 255-48, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(121, 255-48, 148, 255-49, pen);
	XYPlotter_drawLine(148, 255-49, 133, 255-49, pen);
	XYPlotter_drawLine(133, 255-49, 135, 255-75, pen);
	XYPlotter_drawLine(135, 255-75, 121, 255-73, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(154, 255-49, 151, 255-77, pen);
	XYPlotter_drawLine(151, 255-77, 168, 255-75, pen);
	XYPlotter_drawLine(168, 255-75, 172, 255-50, pen);
	XYPlotter_drawLine(172, 255-50, 154, 255-49, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(175, 255-49, 176, 255-73, pen);
	XYPlotter_drawLine(176, 255-73, 191, 255-74, pen);
	XYPlotter_drawLine(191, 255-74, 191, 255-48, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(199, 255-49, 200, 255-75, pen);
	XYPlotter_drawLine(200, 255-75, 199, 255-50, pen);
	XYPlotter_drawLine(199, 255-50, 219, 255-50, pen);
	XYPlotter_drawLine(219, 255-50, 218, 255-62, pen);
	XYPlotter_drawLine(218, 255-62, 199, 255-61, pen);
	XYPlotter_drawLine(199, 255-61, 219, 255-75, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(11, 255-150, 30, 255-99, pen);
	XYPlotter_drawLine(30, 255-99, 40, 255-132, pen);
	XYPlotter_drawLine(40, 255-132, 81, 255-108, pen);
	XYPlotter_drawLine(81, 255-108, 65, 255-166, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(77, 255-170, 100, 255-111, pen);
	XYPlotter_drawLine(100, 255-111, 135, 255-123, pen);
	XYPlotter_drawLine(135, 255-123, 106, 255-177, pen);
	XYPlotter_drawLine(106, 255-177, 77, 255-170, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(120, 255-179, 143, 255-126, pen);
	XYPlotter_drawLine(143, 255-126, 139, 255-186, pen);
	XYPlotter_drawLine(139, 255-186, 175, 255-137, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(155, 255-194, 191, 255-141, pen);
	XYPlotter_drawLine(191, 255-141, 209, 255-169, pen);
	XYPlotter_drawLine(209, 255-169, 184, 255-197, pen);
	XYPlotter_drawLine(184, 255-197, 155, 255-194, pen);
	vTaskDelay(100);
	XYPlotter_drawLine(230, 255-229, 191, 255-209, pen);
	XYPlotter_drawLine(191, 255-209, 229, 255-156, pen);
	XYPlotter_drawLine(229, 255-156, 254, 255-172, pen);
	XYPlotter_drawLine(212, 255-181, 242, 255-196, pen);
	

	GI_uid_t bar_L = NULL;
	GI_uid_t bar_R = NULL;
	GI_uid_t ball = NULL;
	float x_ball = 127;
	float y_ball = 127;
	float vx_ball = 1;
	float vy_ball = 0.7;

	float y_bar_L = 127;
	float y_bar_R = 127;

	int size = 0;
	int cnt = 0;
	while(1) {
		Pen_t penLine = {.spacing = 1, .intensity = 1};
		Pen_t penPoint = {.spacing = 1, .intensity = 5};


		XYPlotter_delete(bar_L);
		XYPlotter_delete(bar_R);
		XYPlotter_delete(ball);

		bar_L = XYPlotter_drawLine(0  , y_bar_L-10, 0  , y_bar_L+10, penLine);
		ball = XYPlotter_drawPoint(x_ball, y_ball, penPoint);
		bar_R = XYPlotter_drawLine(255, y_bar_R-10, 255, y_bar_R+10, penLine);


		if(vx_ball > 0) {
			y_bar_L += ((y_bar_L < y_ball) ? 1 : -1) * -0.33;
			y_bar_R += ((y_bar_R < y_ball) ? 1 : -1) * 1.0;
		} else {
			y_bar_L += ((y_bar_L < y_ball) ? 1 : -1) * 1.0;
			y_bar_R += ((y_bar_R < y_ball) ? 1 : -1) * -0.33;
		}

		y_bar_R = fmax(fmin(y_bar_R, 255-10), 0+10);
		y_bar_L = fmax(fmin(y_bar_L, 255-10), 0+10);

		x_ball += vx_ball * 1.0;
		y_ball += vy_ball * 1.0;

		if( (y_ball <= 0 && vy_ball < 0) || (y_ball >= 255 && vy_ball> 0)) {
			vy_ball *= -1;
			ESP_LOGW(TAG, "Hit one");
		}
		if( (x_ball <= 0 && vx_ball < 0) || (x_ball >= 255 && vx_ball > 0)) {
			vx_ball *= -1;
			ESP_LOGW(TAG, "Hit two");
		}

		x_ball = fmax(fmin(x_ball, 255), 0);
		y_ball = fmax(fmin(y_ball, 255), 0);

		vTaskDelay(10);
		//ESP_LOGW(TAG, "Free heap memory : %d", xPortGetFreeHeapSize());
	}

    return ESP_OK;
}