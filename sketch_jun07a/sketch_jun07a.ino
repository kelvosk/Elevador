#include <Stepper.h>

// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int stepsPerRevolution = 500; 
int CURRENT_FLOOR = 0;
int btn1 = 7;
int btn2 = 2;
int btn3 = 4;

// Inicializa o display no endereco 0x27
Stepper myStepper(stepsPerRevolution, 8,10,9,11);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 pinMode(btn1, INPUT);
 pinMode(btn2, INPUT);
 pinMode(btn3, INPUT);
 myStepper.setSpeed(60);
 lcd.begin (16,2);
 Serial.begin(9600);
}
 
void loop()
{
  if(digitalRead(btn1) == HIGH){
  lcd.setCursor(0,0);
   CURRENT_FLOOR = 0;
  lcd.print(CURRENT_FLOOR);
   //velocidade gradativamente
 for (int i = 10; i<60; i=i+10)
 {
 myStepper.step(1000);
 }
  }
  if(digitalRead(btn2) == HIGH){
  lcd.setCursor(0,0);
  CURRENT_FLOOR = 1;
  lcd.print(CURRENT_FLOOR);
  }
  if(digitalRead(btn3) == HIGH){
  lcd.setCursor(0,0);
  CURRENT_FLOOR = 2;
  lcd.print(CURRENT_FLOOR);
  }
  

}
