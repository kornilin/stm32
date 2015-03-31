/*
 * usart.h
 *
 *  Created on: 21 марта 2015 г.
 *      Author: klan
 */

#ifndef INCLUDE_USART_H_
#define INCLUDE_USART_H_


#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"

namespace USART
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
} UsartState;

typedef enum
{
	usart1 = 0,
	usart1Remap = 1,
	usart2 = 2,
	usart2Remap = 3,
	usart3 = 4,
	usart3Remap = 5,
	usart4 = 6,
	usart4Remap = 7,
	usart5 = 8,
	usart5Remap = 9,
	usart6 = 10,
	usart6Remap = 11
} USARTs;


class Usart
{
	UsartState state;
	USART_InitTypeDef* usart;
	GPIO_TypeDef* port;
	uint16_t pinTx;
	uint16_t pinRx;

	UsartState Init(USARTs usart);
	UsartState DeInit();
public:
	Usart(USARTs usart);
	~Usart();
	UsartState ChangeUsart(USARTs usart);
	UsartState GetState();
};

}


#endif /* INCLUDE_USART_H_ */
