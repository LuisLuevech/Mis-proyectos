//LOS CAÑOS CLOCK 1.0
//by luevech.com  
//Santa Barbara de Casa. Mayo, 2018


#include <OLED_I2C.h>
#include <Wire.h>
#include <DS3231.h>

OLED  myOLED(SDA, SCL);
DS3231 myclock(SDA, SCL);

extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];



Time dt;
word diasemana;
char* mes[]={"Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};

void setup()
{
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myclock.begin();
  myclock.setTime(23,59,55);
  myclock.setDate(28,2,2019);
//  myclock.setDOW=([4]);
  Serial.begin(9600);
  
}

void loop()
{
 
  myOLED.print("LOS CANOS", CENTER, 0);
  myOLED.setFont(BigNumbers);
  dt = myclock.getTime();
  myOLED.printNumI(dt.hour,16,16,2,'0');
  myOLED.printNumI(dt.min, 56,16,2,'0');
  myOLED.printNumI(dt.sec, 96,16,2,'0');
 
  myOLED.setFont(SmallFont);
  myOLED.print(myclock.getDOWStr(FORMAT_LONG), 10, 50);
 
  myOLED.printNumI(dt.date,45,50,2,'0');
  myOLED.print(mes[(dt.mon)-1], 66, 50);
  myOLED.printNumI(dt.year,96,50);
 
  myOLED.update();

}

