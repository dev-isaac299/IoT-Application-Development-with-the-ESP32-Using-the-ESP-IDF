#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//#include "portmacro.h"

#include "rgb_led.h"

void app_main(void)
{
    while (true) {
      rgb_led_wifi_app_started();
      //vTaskDelay(1000 / portTICK_PERIOD_MS);
      sleep(1);
      rgb_led_server_started();
      sleep(1);
      //vTaskDelay(1000 / portTICK_PERIOD_MS);
      rgb_led_wifi_connected();
      sleep(1);
      //vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
