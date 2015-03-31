/*
 * led.h
 *
 *  Created on: 21 марта 2015 г.
 *      Author: Y.Reznikov
 *      yurareznikov1991@gmail.com
 */

#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

namespace LED
{

typedef enum
{
	OFF = 0,
	ON = 1,
	INIT = 2,
	DEINIT = 3,
	OK = 4,
	ERROR = 5,
	ERROR_INIT = 6,
	ERROR_DEINIT = 7,
	ERROR_ON = 8,
	ERROR_OFF = 9,
	ERROR_TOGGLE = 10
} LedState;

typedef enum
{
	portA = 0,
	portB = 1,
	portC = 2,
	portD = 3,
	portE = 4,
	portF = 5,
	portG = 6,
	portH = 7,
	portI = 8
} PORTs;


class Led
{
	LedState state;
	LedState offLevel;
	GPIO_TypeDef* port;
	uint16_t pin;

	LedState Init(PORTs port, uint8_t pin, LedState offLevel = OFF);
	LedState DeInit();
public:
	Led(PORTs port, uint8_t pin, LedState offLevel = OFF);
	~Led();
	LedState ChangePin(PORTs port, uint8_t pin,
			LedState offLevel = OFF);
	LedState GetState();
	LedState SetState(LedState state);
	LedState On();
	LedState Off();
	LedState Toggle();
};

}

#endif /* INCLUDE_LED_H_ */
