/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "sdkconfig.h"

#include "rotary.cpp"


// static const char *TAG = "BlackBox";




extern "C" { void app_main(void); }

void app_main(void)
{
    initRot();
    
    // Report counter value
    int pulse_count = 0;
    int event_count = 0;
    while (1)
    {
        if (xQueueReceive(queue, &event_count, pdMS_TO_TICKS(1000)))
        {
            ESP_LOGI(TAG, "Watch point event, count: %d", event_count);
        }
        else
        {
            ESP_ERROR_CHECK(pcnt_unit_get_count(pcnt_unit, &pulse_count));
            ESP_LOGI(TAG, "Pulse count: %d", pulse_count);
        }
    }
}