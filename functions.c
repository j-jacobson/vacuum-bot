
void setup(){
  
  // Set Outputs
  // Fan - Pin 19 - RD0
  TRISDbits.TRISD0 = 0; 

  // Motor 1 - Pins 21, 22 - RD2, RD3 (J2)
  TRISDbits.TRISD2 = 0;
  TRISDbits.TRISD3 = 0;

  // Motor 2 - Pins 27, 28 - RD4, RD5 (J2)
  TRISDbits.TRISD4 = 0;
  TRISDbits.TRISD5 = 0;


  // Set Inputs
  // Bumper Left - Pin 16 - RC1 (SW1)
  TRISCbits.TRISC1 = 1;

  // Bumper Right - Pin 15 - RC0 (SW2)
  TRISCbits.TRISC0 = 1;

  // Battery Voltage Sensor
  TRISAbits.TRISA0 = 1;
  ANSELAbits.ANSELA0 = 1;

  // Sensor 1 - Front Left - Pin 3 - RA1/AN1 (U2)
  TRISAbits.TRISA1 = 1;
  ANSELAbits.ANSELA1 = 1;

  // Sensor 2 - Front Left - Pin 4 - RA2/AN2 (U3)
  TRISAbits.TRISA2 = 1;
  ANSELAbits.ANSELA2 = 1;

  // Sensor 3 - Front Left - Pin 5 - RA3/AN3 (U5)
  TRISAbits.TRISA3 = 1;
  ANSELAbits.ANSELA3 = 1;

  // Sensor 4 - Front Left - Pin 7 - RA5/AN4 (U6)
  TRISAbits.TRISA5 = 1;
  ANSELAbits.ANSELA4 = 1;

  ADCON = xFF; // turn ADC on for Port A (?)

  // Set Crystal?
    
}

void fanCTRL(boolean fan){
  if(fan){  //fan on
    LATDbits.LATD0 = 1;
  }
  else(){ //fan off
    LATDbits.LATD0 = 0;
  }
}

void stopMotors(){
  LATDbits.LATD2 = 0; // Motor 1 Pin 1
  LATDbits.LATD3 = 0; // Motor 1 Pin 2
  LATDbits.LATD4 = 0; // Motor 2 Pin 1
  LATDbits.LATD5 = 0; // Motor 2 Pin 2
}

void forwardMotors(int moveTime){
  LATDbits.LATD2 = 1; // Motor 1 Pin 1
  LATDbits.LATD3 = 0; // Motor 1 Pin 2
  LATDbits.LATD4 = 1; // Motor 2 Pin 1
  LATDbits.LATD5 = 0; // Motor 2 Pin 2

  delay(moveTime);  
}

void rightMotors(int moveTime){
  LATDbits.LATD2 = 0; // Motor 1 Pin 1
  LATDbits.LATD3 = 1; // Motor 1 Pin 2
  LATDbits.LATD4 = 1; // Motor 2 Pin 1
  LATDbits.LATD5 = 0; // Motor 2 Pin 2

  delay(moveTime);  
}

void leftMotors(int moveTime){
  LATDbits.LATD2 = 1; // Motor 1 Pin 1
  LATDbits.LATD3 = 0; // Motor 1 Pin 2
  LATDbits.LATD4 = 0; // Motor 2 Pin 1
  LATDbits.LATD5 = 1; // Motor 2 Pin 2

  delay(moveTime); 
}

void backwardMotors(int moveTime){
  LATDbits.LATD2 = 0; // Motor 1 Pin 1
  LATDbits.LATD3 = 1; // Motor 1 Pin 2
  LATDbits.LATD4 = 0; // Motor 2 Pin 1
  LATDbits.LATD5 = 1; // Motor 2 Pin 2

  delay(moveTime); 
}
  
float readBattery(){

  //  max batery will get is ((8.4)/5) * inVol = real voltage
  //  anIn / 255 * 5V = inVol
  
  // set the input to be the battery pin (?)
  // read the value from the ADRES register (?)
  


  float analogIn = 

  float Voltage = (analogIn * 8.4) / 255;

  return (Voltage);
}

float readSensor(int sensor){
  
  // analogIn is 0-255
  // sensor max distance is 30cm
  // min distance is 4cm

  float analogIn = 0;

  if(sensor == 0){ // Front Left Sensor

    analogIn = ADRESL
  }

  else if(sensor == 1){ // Front Right Sensor

  }

  /*else if(sensor == 2){ // Left Side Sensor}
  else { // Right Side Sensor}*/

  float Distance = (analogIn * 30 / 255) + 4; // in cm

  return Distance;
}

void chargeMe(){

  // check the battery voltage
  // while low,
  //   // blink the LED

  return;
}


void doneCharging(){
  // slow blink the green LED
  // power everything down.
  // wait forever.

}

// Notes

// TRISAbits.TRISA4 = 0; /* Configure the TRISA4 pin as output */
// TRISAbits.TRISA3 = 1; /* Configure the TRISA4 pin as input*/ 
// 
// LATAbits.LATA4 = 1; /* Drive the output high */
// LATAbits.LATA4 = 0; /* Drive the output low */
// 
// ANSELAbits.ANSELA0 = 0; /* ST and TTL input buffers are enabled */
// ANSELAbits.ANSELA1 = 1; /* Digital input buffers are disabled*/
// 
// WPUAbits.WPUA0 = 1; /* Enable weak pull-up */ 