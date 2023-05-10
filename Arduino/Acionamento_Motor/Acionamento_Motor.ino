#include <Stepper.h>
double stepsPerRevolution = 1024; //Volta completa (2048) 360º
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
void setup() {
 	myStepper.setSpeed(10); 	
 	Serial.begin(9600);
 	}
 	
 	void loop() { 	
    if (Serial.available()) {
      char command = Serial.read();
      if (command == 'L') {
          //Rotaciona no sentido anti-horario			
          myStepper.step(stepsPerRevolution); 	
          delay(3000);
            
         //Rotaciona no sentido horario	
        myStepper.step(-stepsPerRevolution);
      }
    }
}