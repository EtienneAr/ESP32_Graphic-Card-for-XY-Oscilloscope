#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"


esp_err_t app_main()
{
    XYPlotter_init(441000);
    esp_log_level_set("I2S", ESP_LOG_INFO);

	Pen_t myPen = { .spacing = 1, .intensity = 10 };
	XYPlotter_drawLine(0,0, 255,255, myPen);

	Pen_t myPen2 = { .spacing = 50, .intensity = 500 };
	XYPlotter_drawLine(0,255, 255,0, myPen2);

    return ESP_OK;
}