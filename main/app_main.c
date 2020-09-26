#include "esp_err.h"
#include "esp_log.h"

#include "DAC_XY_Plotter.h"


esp_err_t app_main()
{
    XYPlotter_init(44100);
    esp_log_level_set("I2S", ESP_LOG_INFO);
    return ESP_OK;
}


