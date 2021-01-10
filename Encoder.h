/*
 * Encoder.h
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */
#include <Arduino.h>
#include "RangeObj.h"


#ifndef ENCODER_H_
#define ENCODER_H_

class Encoder{
private :
	uint32_t lastSw=0;
	uint8_t pinSw,pinClk,pinClkLast,pinDt;
	RangeObj *range;
	void sensorSw();
	void sensorRotate();



public:
	Encoder(uint8_t pSw,uint8_t pA,uint8_t pB,RangeObj *rng);
	void run();


};


#endif /* ENCODER_H_ */
