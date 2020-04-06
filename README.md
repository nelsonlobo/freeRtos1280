# freeRTOS AtMega1280
---------------------------------------------------------------------  

___
### Toolchain  
    Atmel Studio 7 version 7.0.1931
    Optimization: -Og
	- [x] Prepare function for garbage collection
	- [x] Prepare for Data garbage collection
	- [x] Pack structure members together 
	- [x] Allocate as many bytes to enum
	- [x] Use rjmp/rcall(limited range) on >8k devices

___
### Include Files
	Project-> freeRTOS_1280_v0 properties ->Toolchain->AVR/GNU C Compiler->Directories add following:
	- ..
	- ../freeRTOS/include
	- ../freeRTOS/portable/GCC/ATMega1280
	
___
### Deprecated files
	Following files are maintained in a deprecated folder
	- atomic.h, 
	- deprecated_definitions.h, 
	- event_groups.h, 
	- semphr.h, 
	- StackMacros.h, 
	- stream_buffer.h

### Version - v0 (6th April 2020)
    Written by Nelson Lobo

- Firmware Updates
	- Download [FreeRTOS](https://www.freertos.org/a00104.html)
	- Links associated to exploring the RTOS view following:
	1.[Tickless](http://amichalec.net/2014/01/23/freertos-deep-sleep-atmega128/),
    2.[Atmega4809 demo App](https://github.com/MicrochipTech/freertos-trace_demo_application),
    3.[Atmeg32A](https://www.freertos.org/a00098.html#SourceCodeOrg)
    4.[Video tutorial](https://sites.google.com/view/snomanningenior/home/freertos-tutorial)
	- Exploring freeRTOS by creating a new PORT for 1280
	- Porting only requires you to update the TIMER variables in ..portable/GCC/ATMega1280/ports.c file
	- Created a task using xTaskCreate() to blink  LED every 500ms
	- Deleted the same task using vTaskDelete() 
	- Learnt the difference between vTaskDelay() and vTaskDelayUntil() wherein the latter is more precise since it takes reference from the timer to perform the next delay operations.
	- vTaskStartScheduler() used to initiate the process of rtos.
	- TaskHandle_t used to create objects so that we can keep track of individual tasks.
___