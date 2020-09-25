#include "DAC_XY_Plotter.h"
#include "I2SManager.h"

#include "esp_err.h"
#include "esp_log.h"

static const char* TAG = "XYPlotter";


void XYPlotter_init(int rate) {
	I2SManager_init(rate);
}