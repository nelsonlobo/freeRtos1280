/*
 * IO_Macros.h
 *
 * Created: 28-02-2019 18:01:26
 * Author: Saras Chaudhary, Shubham Gaikwad, Nelson Lobo
 * Tested by: Sowmya Murugesh, Sonali Katkar
 * Regression: Leha Chintal, Vishnu Sudheerthan
 */ 


#ifndef IO_MACROS_H_
#define IO_MACROS_H_

#include "avr/io.h"

//----- I/O Macros -----
//Macros to edit PORT, DDR and PIN
#define PinMode(x, y)			(y?	_SET(DDR, x):_CLEAR(DDR, x))
#define DigitalWrite(x, y)		(y?	_SET(PORT, x):_CLEAR(PORT, x))
#define DigitalRead(x)			(_GET(PIN, x))
#define PinModeToggle(x)		(_TOGGLE(DDR, x))
#define DigitalLevelToggle(x)	(_TOGGLE(PORT, x))

//General use bit manipulating commands
#define BitSet(x, y)			(x |= (1UL<<y))
#define BitClear(x, y)			(x &= (~(1UL<<y)))
#define BitToggle(x, y)			(x ^= (1UL<<y))
#define BitCheck(x, y)			(x &  (1UL<<y)? 1:0)

//Access PORT, DDR and PIN
#define PORT(port)				(_PORT(	port))
#define DDR(port)				(_DDR(	port))
#define PIN(port)				(_PIN(	port))

#define _PORT(port)				(PORT##	port)
#define _DDR(port)				(DDR##	port)
#define _PIN(port)				(PIN##	port)

#define _SET(type, port, bit)		(BitSet((type##port),	bit))
#define _CLEAR(type, port, bit)		(BitClear((type##port),	bit))
#define _TOGGLE(type, port, bit)	(BitToggle((type##port),bit))
#define _GET(type, port, bit)		(BitCheck((type##port),	bit))


#define OUTPUT		1
#define INPUT		0
#define nOUTPUT		0
#define nINPUT		1

#define ENABLE		1
#define DISABLE		0
#define nENABLE		0
#define nDISABLE	1

#define HIGH		1
#define LOW			0
#define nHIGH		0
#define nLOW		1

#define INPUT_PU	1
#define INPUT_HI	0

#define TRUE		1
#define FALSE		0

#define SUCCESS		1
#define FAILED		0

#endif /* IO_MACROS_H_ */