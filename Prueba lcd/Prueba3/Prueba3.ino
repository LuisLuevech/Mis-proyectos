/**
   GeekFactory - "INNOVATING TOGETHER"
   Distribucion de materiales para el desarrollo e innovacion tecnologica
   www.geekfactory.mx
 
   EN ESTE EJEMPLO MOSTRAMOS COMO DEFINIR CARACTERES PERSONALIZADOS EN UNA
   PANTALLA LCD 16X2 CON ARDUINO. EL CODIGO MUESTRA COMO DEFINIR LOS MAPAS
   DE BITS Y COMO INDICARLE AL CONTROLADOR DE PANTALLA QUE MUESTRE LOS CARACTERES
   PERSONALIZADOS EN POSICIONES ESPECIFICAS DE LA PANTALLA.
*/
 
#include  <LiquidCrystal.h>
 
// CONSTRUCTOR PARA LA PANTALLA LCD 16X2
// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// DEFINICION DE CARACTERES PERSONALIZADOS
byte smile[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00010001,
  0b00001110,
  0b00000000,
};
 
byte sad[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00001110,
  0b00010001,
  0b00000000,
};
 
byte body[8] = {
  0b00001110,
  0b00001110,
  0b00000100,
  0b00011111,
  0b00000100,
  0b00001010,
  0b00010001,
  0b00000000,
};
 
byte arrowr[8] = {
  0b00001000,
  0b00000100,
  0b00000010,
  0b00011111,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00000000,
};
 
byte arrowu[8] = {
  0b00000100,
  0b00001110,
  0b00010101,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000000,
};
 
byte arrowd[8] = {
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00010101,
  0b00001110,
  0b00000100,
  0b00000000,
};
 
byte arrowl[8] = {
  0b00000010,
  0b00000100,
  0b00001000,
  0b00011111,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000000,
};
 
 
void setup()
{
  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  lcd.begin(16, 2);
  
  // ENVIAR LOS MAPAS DE BITS AL CONTROLADOR DE PANTALLA
  lcd.createChar (0, smile);
  lcd.createChar (1, sad);
  lcd.createChar (2, body);
  lcd.createChar (3, arrowr);
  lcd.createChar (4, arrowu);
  lcd.createChar (5, arrowd);
  lcd.createChar (6, arrowl);
  
  // LIMPIAR LA PANTALLA Y MOVER EL CURSOR A LA PRIMERA POSICION
  lcd.clear();
  // IMPRIMIR TITULO EN LA PRIMERA LINEA
  lcd.print(" GEEKFACTORY.MX ");
  // MOVER EL CURSOR A LA SEGUNDA LINEA
  lcd.setCursor(0, 1);
 
  // AHORA ESCRIBIMOS (MOSTRAMOS) LOS CARACTERES A LA PANTALLA
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)6);
}
 
void loop()
{
  // NO HACEMOS NADA EN EL LOOP
}
