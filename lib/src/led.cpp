/*
 * led.cpp
 *
 *  Created on: 21 марта 2015 г.
 *      Author: Y.Reznikov
 *      yurareznikov1991@gmail.com
 */

#include "../lib/include/led.h"

using namespace LED;

Led::Led(PORTs port, uint8_t pin, LedState offLevel)
{
	Init(port, pin, offLevel);
}

Led::~Led()
{
	Off();
	DeInit();
}

LedState Led::Init(PORTs port, uint8_t pin, LedState offLevel)
{
	state = INIT;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	switch(port)
	{
	case portA:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
		this->port = GPIOA;
		break;
	case portB:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
		this->port = GPIOB;
		break;
	case portC:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		this->port = GPIOC;
		break;
	case portD:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		this->port = GPIOD;
		break;
	case portE:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		this->port = GPIOE;
		break;
	case portF:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
		this->port = GPIOF;
		break;
	case portG:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
		this->port = GPIOG;
		break;
	case portH:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
		this->port = GPIOH;
		break;
	case portI:
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
		this->port = GPIOI;
		break;
	default:
		state = ERROR_INIT;
		break;
	}

	if(pin < 16)
	{
		this->pin = GPIO_Pin_0 << pin;
		GPIO_InitStructure.GPIO_Pin = this->pin;
	}
	else
		state = ERROR_INIT;

	switch(offLevel)
	{
	case OFF:
		this->offLevel = OFF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		break;
	case ON:
		this->offLevel = ON;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
		break;
	default:
		state = ERROR_INIT;
		break;
	}

	if(state == INIT)
	{
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(this->port, &GPIO_InitStructure);
		GPIO_WriteBit(this->port, this->pin, (BitAction) offLevel);
	}
	return state;
}

LedState Led::DeInit()
{
	state = DEINIT;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = this->pin;
	GPIO_Init(this->port, &GPIO_InitStructure);
	return state;
}

LedState Led::ChangePin(PORTs port, uint8_t pin,
		LedState offLevel)
{
	Off();
	DeInit();
	Init(port, pin, offLevel);
	return state;
}

LedState Led::GetState()
{
	return this->state;
}

LedState Led::SetState(LedState state)
{
	this->state = state;
	return OK;
}

LedState Led::On()
{
	if(state == OFF || state == INIT)
	{
		GPIO_WriteBit(port, pin, (BitAction) !offLevel);
		state = (LedState) (GPIO_ReadOutputDataBit(port, pin) ^ offLevel);
	}
	return state;
}

LedState Led::Off()
{
	if(state == OFF || state == INIT)
	{
		GPIO_WriteBit(port, pin, (BitAction) offLevel);
		state = (LedState) (GPIO_ReadOutputDataBit(port, pin) ^ offLevel);
	}
	return state;
}

LedState Led::Toggle()
{
	if(state == OFF || state == ON || state == INIT)
	{
		GPIO_WriteBit(port, pin, (BitAction) !GPIO_ReadOutputDataBit(port, pin));
		state = (LedState) (GPIO_ReadOutputDataBit(port, pin) ^ offLevel);
	}
	return state;
}

