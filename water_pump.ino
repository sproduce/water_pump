#include "Arduino.h"
#include "RangeObj.h"
#include "Encoder.h"
#include "Sensor.h"
//The setup function is called once at startup of the sketch

LiquidCrystal_I2C lcd(0x3F,4,5);

RangeObj range(&lcd);

Encoder myEncoder(9,8,7,&range);

Sensor mySensor(3,&lcd);
uint8_t pinLevel1=6,pinLevel2=5;



void setup()
{
	pinMode(pinLevel1, OUTPUT);
	digitalWrite(pinLevel1, HIGH);
	pinMode(pinLevel2, OUTPUT);
	digitalWrite(pinLevel2, HIGH);
	lcd.init();
	lcd.backlight();
	range.init();
	//Serial.begin(9600);



// Add your initialization code here
}








void loop()
{

	range.run();//for blink
	myEncoder.run();
	mySensor.run();
if(mySensor.getValue()){


	if(mySensor.getValue()<range.getMinValue()){
		digitalWrite(pinLevel1, LOW);
	}

	if(mySensor.getValue()<range.getMaxValue()){
			digitalWrite(pinLevel2, LOW);
		}

	if(mySensor.getValue()>range.getMinValue()){
			digitalWrite(pinLevel1, HIGH);
		}
	if(mySensor.getValue()>range.getMaxValue()){
				digitalWrite(pinLevel2, HIGH);
			}
}

}
