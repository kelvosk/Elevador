#include <Stepper.h>

const int stepsPerRevolution = 500;
Stepper myStepper(stepsPerRevolution, 8,10,9,11);

void giraNegativo(){

    for (int i = 10; i<60; i=i+10){
        myStepper.step(800);
    }
}

void giraDobroNegativo(){

    for (int i = 10; i<60; i=i+10){
        myStepper.step(1600);
    }
}
void giraPositivo(){

    for (int i = 10; i<60; i=i+10){
        myStepper.step(-800);
    }
}

void giraDobroPositivo(){

    for (int i = 10; i<60; i=i+10){
      myStepper.step(-1600);
    }
}

