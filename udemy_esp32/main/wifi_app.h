/*
 * wifi_app.h
 *
 *  Created on: Jul 3, 2023
 *      Author: ISAAC
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_



#include "esp_netif.h"

#define WIFI_AP_SSID				"ESP32_AP"			/*access point name*/
#define WIFI_AP_PASSWORD			"password"			/*access point password*/
#define WIFI_AP_CHANNEL				1					/*access point channle*/
#define	WIFI_AP_SSID_HIDDEN			0					/*access point visibility*/
#define WIFI_AP_MAX_CONNECTIONS		5					/*max clients*/
#define WIFI_AP_BEACON_INTERVAL		100					/*AP beacon interval*/
#define WIFI_AP_IP					"192.168.0.1"		/*default ip*/
#define WIFI_AP_GATEWAY				"192.168.0.1"		/*should be same as ip*/
#define WIFI_NET_MASK				"255.255.255.0"
#define WIFI_AP_BANDWIDTH			WIFI_BW_HT20		/*AP bandwidth 20 megahertz*/
#define WIFI_STA_POWER_SAVE			WIFI_PS_NONE		/*power save not used*/
#define MAX_SSID_LENGTH				32					/*IEEE Max Length*/
#define MAX_PASSWORD_LENGTH			64					/*IEEE standard*/
#define MAX_CONNECTION_RETRIES		5					/*retry numer on disconnect*/


/*network interface objects for the station and access point*/
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;



/*
 *
 * @brief: Message id for the wifi application task
*/

typedef enum wifi
{
	WIFI_APP_MSG_START_HTTP_SERVER=0,
	WIFI_APP_MSG_CONNECTION_FROM_HTTP_SERVER,
	WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
}wifi_app_message_e;

/*
 * @brief: Structure for the message queue
*/
typedef struct wifi_app_queue_message
{
	wifi_app_message_e msgID;

}wifi_app_queue_message_t;

/*
 * @brief: Sends a message to the queue
 * @param: msgID message ID from the wifi_app_message_e enum
 * @return: pdTRUE if an item was successfully sent to the queue,otherwise pdFALSE
 * @note: Expand the parameter list based on your requirements
*/

BaseType_t	wifi_app_send_message(wifi_app_message_e msgID);

/*Starts the WIFI RTOS TASK*/

void wifi_app_start(void);


#endif /* MAIN_WIFI_APP_H_ */
