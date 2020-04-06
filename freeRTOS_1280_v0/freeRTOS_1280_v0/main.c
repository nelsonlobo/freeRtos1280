/*
 * freeRTOS_1280_v0.c
 *
 * Created: 06-04-2020 12:39:09
 * Author : Nelson Lobo
 */ 

#include <avr/io.h>
#include "IO_Macros.h"
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"

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
/*	Task Handle Creation	*/
TaskHandle_t blinkLedBlue_task1Handle = NULL;
/****************************/

/****************************/
/*	Function declarations	*/
void task_blinkLedBlue(void *p);	//Function declaration for Blue LED
/****************************/


int main(void)
{
	BitSet(DEBUG_LED_DDR, BLUE_LED);
	
	//1st arg: Task Function without brackets, 
	//2nd arg: task name, 
	//3rd arg: stack size, 
	//4th arg: initial value passed to the function, 
	//5th arg: task priority, 
	//6th arg: task handle
	xTaskCreate(task_blinkLedBlue, "Blue", configMINIMAL_STACK_SIZE,(void*) 10, blinkLED_TASK_PRIORITY, &blinkLedBlue_task1Handle);
	
	vTaskStartScheduler();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}


//task_blinkLedBlue() function definition
//Function keeps counting upto 100 post which it will delete itself
//Whilst counting it will also toggle the Blue LED every 500ms
void task_blinkLedBlue(void *p)
{
	uint16_t count = (uint16_t*) p;
	
	TickType_t lastWakeUp;

	//Acquire the information of the actual delay elapsed
	lastWakeUp = xTaskGetTickCount();	
	
	BitSet(DEBUG_LED_PORT, BLUE_LED);
	
	while(1)
	{
		//vTaskDelay() is a generic delays which will offer at the ticks passed to the function, it won't be accurate.
		//vTaskDelay(pdMS_TO_TICKS(500));
				
		//vTaskDelayUntil offers more accuracy compared to vTaskDelay(pdMS_TO_TICKS(500))
		vTaskDelayUntil(&lastWakeUp,pdMS_TO_TICKS(500));
		
		//Toggle Pin to create blink activity
		BitToggle(DEBUG_LED_PORT, BLUE_LED);
		
		if(count++ > 50)
			vTaskDelete(blinkLedBlue_task1Handle);	//Delete task 
	}
}