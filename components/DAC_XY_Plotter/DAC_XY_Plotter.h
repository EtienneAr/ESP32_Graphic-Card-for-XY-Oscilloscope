#ifndef DAC_XY_PLOTTER
#define DAC_XY_PLOTTER

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"

void XYPlotter_init(uint32_t rate);

#endif