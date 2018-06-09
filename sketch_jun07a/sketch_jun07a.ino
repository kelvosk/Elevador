//============Bibliotecas============= 

#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <FuncoesMotor.h>
#include <ControlePisos.h>

//============Variaveis=============

int CURRENT_FLOOR = 0;
int DESTINATION = 0;
int btnT = 7;
int btn1 = 2;
int btn2 = 4;

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 pinMode(btnT, INPUT);
 pinMode(btn1, INPUT);
 pinMode(btn2, INPUT);

 lcd.begin(16,2);
 myStepper.setSpeed(60);
 Serial.begin(9600);
}
 
void loop(){

  lcd.setCursor(4,0);
  lcd.print("Bem vindo");
  lcd.setCursor(5,1);
  lcd.print("Piso:");
  lcd.setCursor(10,1);
  lcd.print(CURRENT_FLOOR);

  if(digitalRead(btnT) == HIGH){
    DESTINATION = 0;
      if(comparaPisos(CURRENT_FLOOR,DESTINATION) == 0){
        if(CURRENT_FLOOR == 1 && DESTINATION == 0){
          giraNegativo();
          CURRENT_FLOOR = DESTINATION;
        }else if(CURRENT_FLOOR == 2 && DESTINATION == 0){
          giraDobroNegativo();    
          CURRENT_FLOOR = DESTINATION;      
        }
      } 
  }
  if(digitalRead(btn1) == HIGH){
    DESTINATION = 1;
      if(comparaPisos(CURRENT_FLOOR,DESTINATION) == 0){
        if(CURRENT_FLOOR == 0 && DESTINATION == 1){
          giraPositivo();
          CURRENT_FLOOR = DESTINATION;
        }else if(CURRENT_FLOOR == 2 && DESTINATION == 1){
          giraNegativo();
          CURRENT_FLOOR = DESTINATION; 
        }
      } 
  }

   if(digitalRead(btn2) == HIGH){
    DESTINATION = 2;
      if(comparaPisos(CURRENT_FLOOR,DESTINATION) == 0){
        if(CURRENT_FLOOR == 1 && DESTINATION == 2){
          giraPositivo();
          CURRENT_FLOOR = DESTINATION;
        }else if(CURRENT_FLOOR == 0 && DESTINATION == 2){
          giraDobroPositivo();
          CURRENT_FLOOR = DESTINATION; 
        }
      } 
  } 
}
