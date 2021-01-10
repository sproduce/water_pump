/*
 * Encoder.cpp
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */

#include "Encoder.h"

Encoder::Encoder(uint8_t pSw,uint8_t pA,uint8_t pB,RangeObj *rng) {
	// TODO Auto-generated constructor stub
	range=rng;
	pinSw=pSw;
	pinClk=pA;
	pinDt=pB;
	pinMode(pinSw,INPUT_PULLUP);
	pinMode(pinClk,INPUT);
	pinMode(pinDt,INPUT);
	pinClkLast=digitalRead(pinClk);
}



void Encoder::sensorSw()
{

	if(!digitalRead(pinSw)){
		if(millis()-lastSw>2000){
			lastSw=millis();
			range->nextStep();
		}
	} else {
		lastSw=millis();
	}
}



void Encoder::sensorRotate()
{
uint8_t readClk,readDt;
	readClk=digitalRead(pinClk);

	if(readClk!=pinClkLast){
		pinClkLast=readClk;
		if(readClk){
			readDt=digitalRead(pinDt);
					if(readClk==readDt){
						range->dec();
					} else{
						range->inc();
					}
		}

	};
}



void Encoder::run()
{
	sensorSw();
	sensorRotate();
}

