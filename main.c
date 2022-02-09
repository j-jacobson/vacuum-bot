/*
  * File:   main.c
 * Author: Jonathan L. Jacobson
 *
 * Created on October 8, 2021, 1:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
/*
 * 
 */
int main(int argc, char** argv) {
    
  setup();

  if(readBattery() > 6.6)
    fanCTRL(1);
  
  while(readBattery() > 6.6){
    L_bumper_State = PORTCbits.RC1;
    R_bumper_State = PORTCbits.RC0;
        
    if(readSensor(1) <= MIN_DIST){ // Front Left
      if(counter == 2){
        counter = 0;
      }

      forwardMotors(100);
      backwardMotors(500);
      leftMotors(500);

      counter +=2;
      forward = false;
    }

    else if(readSensor(2) <= MIN_DIST){ // Front Right
      if (counter ==1){
        counter = 0;
      }

      forwardMotors(100);
      backwardMotors(500);
      rightMotors(500);

      counter +=1;
      forward = false;
    }

    else if(!L_bumper_State){ // Left Bumper Activated
      
      backwardMotors(1000); 
      rightMotors(500);

      counter +=2;
      forward = false;
    }

    else if(!R_bumper_State){ // Right Bumper Activated 
      
      backwardMotors(1000);
      leftMotors(500);

      counter +=2;
      forward = false;
    }

    else {
      if(counter >= 3){ // Corner Detected
        backwardMotors(3000);
        leftMotors(2000);
      
        counter = 0;
        forward = false;
      }

      else { // Moving Forward
        forwardMotors(0);
        forward = true;
      }
    }

    else {
      // Low Battery!
      stopMotors();
      fanCTRL(0); // fan OFF
      chargeMe(); // waits until voltage increases

      doneCharging(); // blink green led slowly to show
                      // charging complete

    }
  }
}

