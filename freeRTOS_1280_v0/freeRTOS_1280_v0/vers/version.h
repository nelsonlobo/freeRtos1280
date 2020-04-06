/*
 * version.h
 *
 * Created: 06-04-2020 20:14:41
 *  Author: HP
 */ 


#ifndef VERSION_H_
#define VERSION_H_

#include "avr/io.h"
#include "IO_Macros.h"
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"

#define VERSION_1

#define RPAUSE_LED_PORT	PORTH
#define RPAUSE_LED_PIN	PH6
#define SEAT_LED_PORT	PORTE
#define SEAT_LED_PIN	PE3
#define IGN_LED_PORT	PORTL
#define IGN_LED_PIN		PL3

#define DEBUG_LED_DDR	DDRH
#define DEBUG_LED_PORT	PORTH
#define RED_LED		PH4
#define GREEN_LED	PH5
#define BLUE_LED	PH3

#define blinkLED_TASK_PRIORITY	( tskIDLE_PRIORITY)


/****************************/
/*	Function declarations	*/
void task_blinkLedRed(void *p);		//Function declaration for Red LED
void task_blinkLedGreen(void *p);	//Function declaration for Green LED
void task_blinkLedBlue(void *p);	//Function declaration for Blue LED
/****************************/

void taskInit(void);

#endif /* VERSION_H_ */