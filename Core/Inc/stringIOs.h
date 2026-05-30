/*
 * stringIOs.h
 *
 *  Created on: 2026年5月19日
 *      Author: AH
 */

#pragma once


#include "main.h"
#include "note.h"

#define STRING_NUMBER 14

struct StringIO
{
	uint8_t strength;
	uint8_t lastTouch;

	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;

	int16_t *note;
};

struct StringIO stringIOs[STRING_NUMBER] = {};

void initStringIO(struct StringIO *str, GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, int16_t *note)
{
	str->strength = 0;
	str->lastTouch = 0;
	str->GPIOx = GPIOx;
	str->GPIO_Pin = GPIO_Pin;
	str->note = note;
}

//fixed
void initStringIOs()
{
	initStringIO(&stringIOs[0], GPIOA, GPIO_PIN_9, A4);
	initStringIO(&stringIOs[1], GPIOA, GPIO_PIN_10, A5);
	initStringIO(&stringIOs[2], GPIOA, GPIO_PIN_11, B4);
	initStringIO(&stringIOs[3], GPIOA, GPIO_PIN_12, B5);
	initStringIO(&stringIOs[4], GPIOA, GPIO_PIN_3, C5);
	initStringIO(&stringIOs[5], GPIOA, GPIO_PIN_2, C6);
	initStringIO(&stringIOs[6], GPIOA, GPIO_PIN_1, D5);
	initStringIO(&stringIOs[7], GPIOA, GPIO_PIN_0, D6);
	initStringIO(&stringIOs[8], GPIOB, GPIO_PIN_9, E5);
	initStringIO(&stringIOs[9], GPIOB, GPIO_PIN_3, E6);
	initStringIO(&stringIOs[10], GPIOB, GPIO_PIN_4, F5);
	initStringIO(&stringIOs[11], GPIOB, GPIO_PIN_5, F6);
	initStringIO(&stringIOs[12], GPIOB, GPIO_PIN_7, G5);
	initStringIO(&stringIOs[13], GPIOB, GPIO_PIN_6, G6);
}

void calcStrength(struct StringIO *str)
{
	if(HAL_GPIO_ReadPin(str->GPIOx, str->GPIO_Pin) == GPIO_PIN_RESET)
	{
		str->strength = 0;
		str->lastTouch = 0;
		return;
	}
	if(str->strength)
	{
		str->strength -= 1;
	}
	else if(str->lastTouch == 0)
	{
		str->strength = MAX_STRENGTH-1;
	}
	str->lastTouch = 1;
}

