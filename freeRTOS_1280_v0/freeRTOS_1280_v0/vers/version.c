/*
 * version.c
 *
 * Created: 06-04-2020 20:13:53
 *  Author: Nelson Lobo
 */ 


#include "version.h"


#ifdef VERSION_0

/****************************/
/*	Task Handle Creation	*/
TaskHandle_t blinkLedBlue_task3Handle = NULL;
/****************************/


void taskInit(void)
{
	BitSet(DEBUG_LED_DDR, BLUE_LED);
		
	//1st arg: Task Function without brackets,
	//2nd arg: task name,
	//3rd arg: stack size,
	//4th arg: initial value passed to the function,
	//5th arg: task priority,
	//6th arg: task handle
	xTaskCreate(task_blinkLedBlue, "Blue", configMINIMAL_STACK_SIZE,(void*) 10, blinkLED_TASK_PRIORITY, &blinkLedBlue_task3Handle);
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
		vTaskDelete(blinkLedBlue_task3Handle);	//Delete task
	}
}
#endif

#ifdef VERSION_1

/****************************/
/*	Task Handle Creation	*/
TaskHandle_t blinkLedRed_task1Handle = NULL;
TaskHandle_t blinkLedGreen_task2Handle = NULL;
TaskHandle_t blinkLedBlue_task3Handle = NULL;
/****************************/

void taskInit(void)
{
	//Set pins as output
	BitSet(DEBUG_LED_DDR, RED_LED);
	BitSet(DEBUG_LED_DDR, GREEN_LED);
	BitSet(DEBUG_LED_DDR, BLUE_LED);
	
	//Active Low signals
	BitSet(DEBUG_LED_PORT,RED_LED);
	BitSet(DEBUG_LED_PORT,GREEN_LED);
	BitSet(DEBUG_LED_PORT,BLUE_LED);
	
	//Task Creation
	xTaskCreate(task_blinkLedRed,	"Red",		configMINIMAL_STACK_SIZE,(void*) 0, blinkLED_TASK_PRIORITY, &blinkLedRed_task1Handle);
	xTaskCreate(task_blinkLedGreen, "Green",	configMINIMAL_STACK_SIZE,(void*) 0, blinkLED_TASK_PRIORITY, &blinkLedGreen_task2Handle);
	xTaskCreate(task_blinkLedBlue,	"Blue",		configMINIMAL_STACK_SIZE,(void*) 0, blinkLED_TASK_PRIORITY, &blinkLedBlue_task3Handle);
}


//task_blinkLedRed() function definition
void task_blinkLedRed(void *p)
{
	while(1)
	{
		//Toggle Pin to create blink activity
		BitToggle(DEBUG_LED_PORT, RED_LED);
		
		//vTaskDelay() is a generic delays which will offer at the ticks passed to the function, it won't be accurate.
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}


//task_blinkLedGreen() function definition
void task_blinkLedGreen(void *p)
{
	while(1)
	{
		//vTaskDelay() is a generic delays which will offer at the ticks passed to the function, it won't be accurate.
		vTaskDelay(pdMS_TO_TICKS(3000));

		vTaskSuspend(blinkLedRed_task1Handle);
		BitSet(DEBUG_LED_PORT, RED_LED);

		for(uint8_t i = 0; i < 12; i++)
		{
			//Toggle Pin to create blink activity
			BitToggle(DEBUG_LED_PORT, GREEN_LED);
			vTaskDelay(pdMS_TO_TICKS(250));
		}
	}
}

//task_blinkLedBlue() function definition
void task_blinkLedBlue(void *p)
{	
	while(1)
	{
		//vTaskDelay() is a generic delays which will offer at the ticks passed to the function, it won't be accurate.
		vTaskDelay(pdMS_TO_TICKS(6000));

		vTaskSuspend(blinkLedGreen_task2Handle);
		BitSet(DEBUG_LED_PORT, GREEN_LED);

		for(uint8_t i = 0; i < 12; i++)
		{
			//Toggle Pin to create blink activity
			BitToggle(DEBUG_LED_PORT, BLUE_LED);
			vTaskDelay(pdMS_TO_TICKS(250));
		}
		
		vTaskResume(blinkLedRed_task1Handle);
		vTaskResume(blinkLedGreen_task2Handle);
	}
}
#endif