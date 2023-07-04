/*
 * rgb_led.h
 *
 *  Created on: Jul 3, 2023
 *      Author: ISAAC
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

/*RGB LED GPIOs*/

#define RGB_LED_RED_GPIO	21
#define RGB_LED_GREEN_GPIO 	22
#define RGB_LED_BLUE_GPIO	23

/*RGB LED color mix channels*/

#define RGB_LED_CHANNEL_NUM		3


/*RGB LED Configuration*/

typedef struct
{
	int channel;
	int gpio;
	int mode;
	int timer_index;

} ledc_info_t;

/*
 *
 * @brief: color to indicate wifi application has started.
 *
 *
*/
void rgb_led_wifi_app_started(void);

/*
 *
 * @brief: color to indicate http server has started.
 *
*/

void rgb_led_server_started(void);

/*
 *
 * @brief: color to indicate esp32 is connected to access point
 *
*/
void rgb_led_wifi_connected(void);


#endif /* MAIN_RGB_LED_H_ */
