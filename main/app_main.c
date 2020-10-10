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

    Pen_t pen = {.spacing = 1, .intensity = 2};

    /*
	XYPlotter_drawLine(0, 0, 255, 255, pen);
	XYPlotter_drawLine(255, 0, 0, 0, pen);
	XYPlotter_drawLine(255, 255, 255, 0, pen);
	XYPlotter_drawLine(0, 255, 255, 255, pen);
    XYPlotter_drawLine(0, 0, 0, 255, pen);
	*/

    //XYPlotter_drawLine(50, 150, 50, 50, pen);
    XYPlotter_drawArc(100, 150, 50, 0, 3.141592, pen);
    XYPlotter_drawRect(50, 50, 150, 150, pen);
    XYPlotter_drawChar('a', 100,100, 28, pen);
    XYPlotter_drawChar('B', 150,100, 28, pen);

	
	

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