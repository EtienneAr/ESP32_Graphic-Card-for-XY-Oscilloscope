#ifndef I2S_MANAGER_H
#define I2S_MANAGER_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void I2SManager_init(int rate);

void I2SManager_write_16bitLR(const void *src, size_t size, size_t *bytes_written, TickType_t ticks_to_wait);
void I2SManager_write_8bitLR(const void *src, size_t size, size_t *bytes_written, TickType_t ticks_to_wait);


#endif