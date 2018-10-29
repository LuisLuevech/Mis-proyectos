/* DEPOSITOS 1.0
 * by Luevech.2018
 * www.luevech.com
 * Los Caños 
 * Santa Barbara de Casa
 * 08/03/2018
 */

#include <LiquidCrystal.h>
#include "SR04.h"

SR04 sr041 = SR04(10,13);
SR04 sr042 = SR04(9,8);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//DEFINICION DE LOS GRAFICOS DEL DEPOSITO
byte cien[8]={
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};
byte ochenta[8]={
  0b00010001,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};
byte setenta[8]={
  0b00010001,
  0b00010001,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};
byte cincuenta[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};

byte cuarenta[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};

byte veinte[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00011111,
  0b00011111,
  0b00011111,
};
byte catorce[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00011111,
  0b00011111,
};
byte cero[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00011111,
};
  int distancia1;
  int litros1;
  int porcentaje1;
  char dibujo1;
  int distancia2;
  int litros2;
  int porcentaje2;
  char dibujo2;

 void setup() {
  lcd.begin (16,2);
  //ENVIAMOS LOS MAPAS DE BITS AL CONTROLADOR DE PANTALLA  
  lcd.createChar(0,cien);
  lcd.createChar(1,ochenta);
  lcd.createChar(2,setenta);
  lcd.createChar(3,cincuenta);
  lcd.createChar(4,cuarenta);
  lcd.createChar(5,veinte);
  lcd.createChar(6,catorce);
  lcd.createChar(7,cero);

 lcd.clear();
 lcd.setCursor(3,0);
 lcd.print("LOS CANOS");
 lcd.setCursor(1,1);
 lcd.print("by luevech.com");
 delay(5000);
 }
void loop(){
//  for (int i=0 ; i<=100 ; i=i+2){
    lcd.clear();
    distancia1=sr041.Distance();
    distancia2=sr042.Distance();
    litros1=1000-distancia1*10;
    litros2=1000-distancia2*10;
    porcentaje1=int(litros1/10);
    porcentaje2=int(litros2/10);
    if(porcentaje1>90){
        lcd.setCursor(15,0);
        lcd.write((byte)0);}
    else if ((porcentaje1>78) && (porcentaje1<91)){
        lcd.setCursor(15,0);
        lcd.write((byte)1);}
    else if((porcentaje1>65) && (porcentaje1<79)){
        lcd.setCursor(15,0);
        lcd.write((byte)2);}
    else if ((porcentaje1>51) && (porcentaje1<66)){
        lcd.setCursor(15,0);
        lcd.write((byte)3);}
    else if ((porcentaje1>38) && (porcentaje1<52)){
        lcd.setCursor(15,0);
        lcd.write((byte)4);}
    else if ((porcentaje1>25) && (porcentaje1<39)){
        lcd.setCursor(15,0);
        lcd.write((byte)5);}
    else if((porcentaje1>11) && (porcentaje1<26)){
        lcd.setCursor(15,0);
        lcd.write((byte)6);}
    else if (porcentaje1<12){
        lcd.setCursor(15,0);
        lcd.write((byte)7);}
    if(porcentaje2>90){
        lcd.setCursor(15,1);
        lcd.write((byte)0);}
    else if ((porcentaje2>78) && (porcentaje2<91)){
        lcd.setCursor(15,1);
        lcd.write((byte)1);}
    else if((porcentaje2>65) && (porcentaje2<79)){
        lcd.setCursor(15,1);
        lcd.write((byte)2);}
    else if ((porcentaje2>51) && (porcentaje2<66)){
        lcd.setCursor(15,1);
        lcd.write((byte)3);}
    else if ((porcentaje2>38) && (porcentaje2<52)){
        lcd.setCursor(15,1);
        lcd.write((byte)4);}
    else if ((porcentaje2>25) && (porcentaje2<39)){
        lcd.setCursor(15,1);
        lcd.write((byte)5);}
    else if((porcentaje2>11) && (porcentaje2<26)){
        lcd.setCursor(15,1);
        lcd.write((byte)6);}
    else if (porcentaje2<12){
        lcd.setCursor(15,1);
        lcd.write((byte)7);}
   
    lcd.setCursor(0,0);
    lcd.print ("D1");
    lcd.setCursor(0,1);
    lcd.print ("D2");

    lcd.setCursor(3,0);
    lcd.print("L");
    lcd.setCursor(3,1);
    lcd.print("L");

    lcd.setCursor(4,0);
    lcd.print (litros1);

    lcd.setCursor(4,1);
    lcd.print (litros2);

    lcd.setCursor(9,0);
    lcd.print("%");
    lcd.print (porcentaje1);
    lcd.setCursor(9,1);
    lcd.print("%");
    lcd.print (porcentaje2);

 
    
    delay(10000);
  //}

 }
