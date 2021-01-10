/*
 * Sensor.cpp
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */

#include "Sensor.h"

Sensor::Sensor(uint8_t pin,LiquidCrystal_I2C *lcd) {
	pLcd=lcd;
	pinMode(pin,INPUT);
	pinSensor=pin;
	// TODO Auto-generated constructor stub

}




void Sensor::run(){

	if(millis()-lastTime>2000){
		addMeter(analogRead(pinSensor));
		lastTime=millis();
	}


}


float Sensor::getValue(){
	//return 0.5;
return pressure;
}


void Sensor::addMeter(uint16_t value){

	uint8_t i,kol_low=0;

		const uint8_t kol=9;
		for(i=0;i<kol;i++){
	    		if(value>CollectionResult[i]){kol_low++;}
	   	}
	   	if(kol_low<kol/2){
	   		for(i=kol-1;i>kol_low;i--){
	  			CollectionResult[i]=CollectionResult[i-1];
	   		}
	   		CollectionResult[kol_low]=value;
	   	} else{
	   		kol_low--;
	   		for(i=0;i<kol_low;i++){
	   			CollectionResult[i]=CollectionResult[i+1];
	   		}
	   		CollectionResult[kol_low]=value;
	   	}


	   	if(kolValue>20){
	   		pressure=CollectionResult[4];
	   		pressure=((pressure+10)/1024-0.1)/0.75*10;
	   		//result=result*5/1023;

	   		//Serial.println(CollectionResult[4]*5/1024);
	   		pLcd->setCursor(6,1);
	   		pLcd->print("    ");
	   		pLcd->setCursor(6,1);
	   		myLine=String(pressure,2);
	   		pLcd->print(myLine);
	   	} else {
	   		kolValue++;
	   	}

}

