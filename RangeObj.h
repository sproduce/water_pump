/*
 * RangeObj.h
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "avr/eeprom.h"
#ifndef RANGEOBJ_H_
#define RANGEOBJ_H_

class RangeObj {
private:
	struct _options{
	float minValue,maxValue,currentValue,step;
	uint8_t col,row;
	}rangeValue[2];
	String myLine;
	LiquidCrystal_I2C *pLcd;
	uint8_t currentStep=0;
	uint8_t status;
	uint32_t lastTime=0;
	void show();
	void hide();
	void showMin();
	void showMax();





public:
	RangeObj(LiquidCrystal_I2C *lcd);
	void init();
	void run();
	void nextStep();
	void inc();
	void dec();
	float getMinValue();
	float getMaxValue();
};

#endif /* RANGEOBJ_H_ */
