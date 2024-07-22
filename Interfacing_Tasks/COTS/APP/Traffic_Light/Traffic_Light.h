/*
 * Traffic_Light.h
 *
 *  Created on: Jul 20, 2024
 *      Author: Mohammad Tamer
 */

#ifndef APP_TRAFFIC_LIGHT_TRAFFIC_LIGHT_H_
#define APP_TRAFFIC_LIGHT_TRAFFIC_LIGHT_H_

#define CAR_GREEN_PORT DIO_PORT_A
#define CAR_GREEN_PIN DIO_PIN_6
#define CAR_YELLOW_PORT DIO_PORT_A
#define CAR_YELLOW_PIN DIO_PIN_3
#define CAR_RED_PORT DIO_PORT_A
#define CAR_RED_PIN DIO_PIN_0

#define PED_RED_PORT DIO_PORT_D
#define PED_RED_PIN DIO_PIN_0
#define PED_YELLOW_PORT DIO_PORT_D
#define PED_YELLOW_PIN DIO_PIN_3
#define PED_GREEN_PORT DIO_PORT_D
#define PED_GREEN_PIN DIO_PIN_6

#define BUTTON_PORT DIO_PORT_B
#define BUTTON_PIN DIO_PIN_2

extern volatile char mode; // 0 for Normal Mode, 1 for Pedestrian Mode
extern volatile char state; // Traffic light state
extern volatile char PED_mode; // Pedestrian mode state

void Init_voidTrafficLightSystem(void);

void Timer_voidISR(void);

void Button_voidISR(void);

#endif /* APP_TRAFFIC_LIGHT_TRAFFIC_LIGHT_H_ */
