/*
 * Sensor.h
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor {
private:
	LiquidCrystal_I2C *pLcd;
	uint8_t pinSensor,kolValue=0;
	uint16_t CollectionResult[9];
	uint32_t lastTime=0;
	float pressure=0;
	String myLine;
	void addMeter(uint16_t value);


public:
	Sensor(uint8_t pin,LiquidCrystal_I2C *lcd);
	void run();
	float getValue(void);
};

#endif /* SENSOR_H_ */
