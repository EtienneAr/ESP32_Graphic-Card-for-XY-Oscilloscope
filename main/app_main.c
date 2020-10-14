#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "Main_app";

#include <math.h>
#define DRAWLINE(dist, angle_a, angle_b) XYPlotter_drawLine(127+dist*cos(angle_a*3.141592/180.),127+dist*sin(angle_a*3.141592/180.),127+dist*cos(angle_b*3.141592/180.),127+dist*sin(angle_b*3.141592/180.), pen)

#define MIN_MAX_0_255(x) ((x < 0) ? 0 : ((x > 255) ? 255 : x))

Pen_t penStr = {.spacing = 1, .intensity = 1};
Pen_t penPlane = {.spacing = 1, .intensity = 2};
Pen_t penCirc = {.spacing = 5, .intensity = 3};

GI_uid_t triangle[3] = {NULL};

typedef struct Circle {
	int x;
	int y;
	int t;
	GI_uid_t id;
} Circle_t;

int circle_index = 0;
Circle_t circles[100] = {NULL};

void drawCircle(float t) {
	for(int i=0;i<circle_index;i++) {
		GI_uid_t temp = XYPlotter_drawArc(circles[i].x, circles[i].y, t - circles[i].t, 0, 2*3.141592, penCirc);
		XYPlotter_delete(circles[i].id);
		circles[i].id = temp;
	}
}

esp_err_t app_main()
{
    XYPlotter_init(1000000);
    esp_log_level_set("I2S", ESP_LOG_INFO);

    XYPlotter_drawString("Le choc", 40, 30, 28, penStr);
    XYPlotter_drawString("supersonique", 10, 0, 28, penStr);
    //XYPlotter_drawArc(127, 127, 127, 0, 2*3.141592, pen_circ);
	//XYPlotter_drawLine(0  , y_bar_L-10, 0  , y_bar_L+10, penLine);
	triangle[0] = XYPlotter_drawLine(0, 155, 0, 145, penPlane);
	triangle[1] = XYPlotter_drawLine(0, 145, 10, 150, penPlane);
	triangle[2] = XYPlotter_drawLine(10, 150, 0, 155, penPlane);

    int x_plane = 5;
    int y_plane = 155;
    float t = 0;
	while(1) {
		if(x_plane < 250) {
			XYPlotter_move(triangle[0], 1, 0);
			XYPlotter_move(triangle[1], 1, 0);
			XYPlotter_move(triangle[2], 1, 0);
		} else if(x_plane == 250) {
			XYPlotter_delete(triangle[0]);
			XYPlotter_delete(triangle[1]);
			XYPlotter_delete(triangle[2]);
		}

		if(x_plane%1 == 0) {
			drawCircle(t);
		}

		vTaskDelay(50);
		x_plane += 1;
		t = x_plane / 1.4;

		if(x_plane % 32 == 0 && x_plane < 300) {
			circles[circle_index].x = x_plane;
			circles[circle_index].y = y_plane;
			circles[circle_index].t = t;
			circles[circle_index].id = NULL;
			circle_index++;
		}
	}

    return ESP_OK;
}