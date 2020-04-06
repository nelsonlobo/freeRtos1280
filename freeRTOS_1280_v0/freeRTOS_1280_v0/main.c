/*
 * freeRTOS_1280_v0.c
 *
 * Created: 06-04-2020 12:39:09
 * Author : Nelson Lobo
 */ 

#include <avr/io.h>
#include "vers/version.h"


int main(void)
{
	taskInit();
 	vTaskStartScheduler();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}