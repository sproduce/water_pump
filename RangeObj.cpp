/*
 * RangeObj.cpp
 *
 *  Created on: 7 янв. 2021 г.
 *      Author: volodia
 */

#include "RangeObj.h"

RangeObj::RangeObj(LiquidCrystal_I2C *lcd) {
	// TODO Auto-generated constructor stub
	this->pLcd=lcd;

}

void RangeObj::init(){
	rangeValue[0].minValue=0.2;
	rangeValue[0].maxValue=1.1;
	rangeValue[0].step=0.01;
	rangeValue[0].currentValue=eeprom_read_float(0);
	rangeValue[0].col=0;
	rangeValue[0].row=1;
	showMin();

	rangeValue[1].minValue=1.2;
	rangeValue[1].maxValue=1.8;
	rangeValue[1].step=0.01;
	rangeValue[1].currentValue=eeprom_read_float(4);

	rangeValue[1].col=12;
	rangeValue[1].row=1;
	showMax();

}


void RangeObj::showMin(){
	pLcd->setCursor(0,0);
	pLcd->print("MIN");


	pLcd->setCursor(rangeValue[0].col,rangeValue[0].row);
	myLine=String(rangeValue[0].currentValue,2);
	pLcd->print(myLine);
}


void RangeObj::showMax(){
	pLcd->setCursor(12,0);
	pLcd->print("MAX");


	pLcd->setCursor(rangeValue[1].col,rangeValue[1].row);
	myLine=String(rangeValue[1].currentValue,2);
	pLcd->print(myLine);
}


void RangeObj::show(){
	pLcd->setCursor(rangeValue[currentStep-1].col,rangeValue[currentStep-1].row);
	myLine=String(rangeValue[currentStep-1].currentValue,2);
	pLcd->print(this->myLine);
}



void RangeObj::hide(){
	pLcd->setCursor(rangeValue[currentStep-1].col,rangeValue[currentStep-1].row);
	pLcd->print("    ");
}



void RangeObj::nextStep(){
	if(currentStep){
		show();
		eeprom_update_float((currentStep-1)*4,rangeValue[currentStep-1].currentValue);
	}
	currentStep++;
	if(currentStep>2){
		currentStep=0;
	}


}


void RangeObj::inc(){
	if(currentStep){
		rangeValue[currentStep-1].currentValue+=rangeValue[currentStep-1].step;
		if(rangeValue[currentStep-1].currentValue>rangeValue[currentStep-1].maxValue){
			rangeValue[currentStep-1].currentValue=rangeValue[currentStep-1].maxValue;
		}
		show();
	}
}



void RangeObj::dec(){
	if(currentStep){
		rangeValue[currentStep-1].currentValue-=rangeValue[currentStep-1].step;
			if(rangeValue[currentStep-1].currentValue<rangeValue[currentStep-1].minValue){
				rangeValue[currentStep-1].currentValue=rangeValue[currentStep-1].minValue;
			}
		show();
	}

}


float RangeObj::getMinValue(){
	return rangeValue[0].currentValue;
}

float RangeObj::getMaxValue(){
	return rangeValue[1].currentValue;
}



void RangeObj::run(){
	if(currentStep){
		if(millis()-lastTime>700){
			status=1-status;
			if(status){
				lastTime=millis();
				show();
			} else {
				lastTime=millis()-500;
				hide();
			}

		}
	}

}





