// ESTACION METEROLOGICA
// LOS CAÑOS
// Octubre 2018 Version 2.1
//
// www.luevech.com  
// La version 2.1 hace uso de las interrupciones para activar la parte meterologica
//

//librerias TFT
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
//Librerias DHT22
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
//Libreria BME280
#include "SparkFunBME280.h"
//Librerias del reloj
#include <OLED_I2C.h>
#include <Wire.h>
#include <DS3231.h>



extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];


#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define DHTPIN            10
#define DHTTYPE           DHT22

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

DHT_Unified dht(DHTPIN, DHTTYPE);
OLED  myOLED(SDA, SCL);
DS3231 myclock(SDA, SCL);

extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];

BME280 mySensorA;
Time dt;
word diasemana;
char* mes[]={"Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
const int intPin=0;

void setup() {
  pinMode(intPin,INPUT);
  attachInterrupt ( digitalPinToInterrupt(intPin),meteo,CHANGE);
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));
   myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myclock.begin();
  myclock.setTime(23,59,55);
  myclock.setDate(28,2,2019);
//  myclock.setDOW=([4]);
  

#ifdef USE_Elegoo_SHIELD_PINOUT
  Serial.println(F("Using Elegoo 2.4\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Elegoo 2.4\" TFT Breakout Board Pinout"));
#endif

  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());

  tft.reset();
  tft.begin(0x9341);
  tft.fillScreen(BLACK);
  Wire.begin();
  mySensorA.setI2CAddress(0x76);
  if(mySensorA.beginI2C() == false) Serial.println("Sensor A connect failed");
  dht.begin();
  
}

void loop() {

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
void meteo(){
  
  sensors_event_t event;  
  
  
  tft.begin(0x9341);
  tft.fillScreen(BLACK);

  // tft.fillScreen(BLACK);
  unsigned long start = micros();
  tft.setCursor(65,7);

  tft.drawRoundRect(2,2,235,30,10,0xF800);
  tft.setTextColor(RED);  tft.setTextSize(2);
  tft.println("Los Canos");
  //PARAMETROS INTERIORES
  tft.setCursor(10,35);
  tft.setTextColor(BLUE);  tft.setTextSize(2);
  tft.println("Interior");
  tft.drawLine(0,51,249,51,BLUE);

  tft.setCursor(10,57);
  tft.setTextColor(GREEN);  tft.setTextSize(3);
  //tft.println("  ");
  tft.setCursor(10,57);
  dht.temperature().getEvent(&event);
  tft.println(event.temperature);
  tft.setCursor(100,57);
  tft.setTextSize(1);
  tft.println("o");
  tft.setTextSize(3);
  tft.setCursor(108,57);
  tft.println("C");
  
  tft.setCursor(150,57);
  tft.setTextColor(GREEN);  tft.setTextSize(3);
  dht.humidity().getEvent(&event);
  tft.println(int(event.relative_humidity));
  tft.setCursor(195,57);
  tft.println("%");
  //PARAMETROS EXTERIORES
  tft.setCursor(10,125);
  tft.setTextColor(BLUE);  tft.setTextSize(2);
  tft.println("Exterior");
  tft.drawLine(0,141,249,141,BLUE);

  tft.setCursor(10,146);
  tft.setTextColor(GREEN);  tft.setTextSize(3);
  tft.println(mySensorA.readTempC());
  tft.setCursor(100,146);
  tft.setTextSize(1);
  tft.println("o");
  tft.setTextSize(3);
  tft.setCursor(108,146);
  tft.println("C");

  tft.setCursor(150,146);
  tft.setTextColor(GREEN);  tft.setTextSize(3);
  tft.println(mySensorA.readFloatHumidity(), 0);
  tft.setCursor(195,146);
  tft.println("%");

  tft.setCursor(30,177);
  tft.setTextColor(GREEN);  tft.setTextSize(3);
  tft.println(int(mySensorA.readFloatPressure()/100));
  tft.setCursor(170,177);
  tft.println("hPa");

  tft.setCursor(45,235);
  tft.setTextColor(YELLOW); tft.setTextSize(2);
  tft.println("Paqui y Luis");

  tft.setCursor(10,270);
  tft.setTextColor(RED);  tft.setTextSize(2);
  tft.println("Sta.Barbara de Casa");
  
  tft.setCursor(100,290);
  tft.setTextColor(RED);  tft.setTextSize(3);
  tft.println(mySensorA.readFloatAltitudeMeters(), 1);
  
  
  delay(1000);delay(1000);delay(1000);delay(1000);delay(1000);
}
