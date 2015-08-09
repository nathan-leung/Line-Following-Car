#include "UW_GENE_121.h"

const int PWR = 50;

//line following function
void stayOnTrack (int PWR) // PWR is the desired power for the motors
{
  setMotor(MOTOR_A, -PWR);
  setMotor(MOTOR_B, PWR);
  
  LEDnum(0);
  int count = 0;
  bool seeingBlack;
  while(getSensor(BUMPER) == 0 && count < 2) // make sure it hasn't crashed
  {
   
    wait1Msec(50);
    //Both sensors detect white or black -> Don't Change anything
    while (getSensor(REFLECT_1) >= 200 && getSensor(REFLECT_2) >= 200
           && getSensor(BUMPER) == 0)
    {
      seeingBlack = false;
      setMotor(MOTOR_A, -PWR); 
      setMotor(MOTOR_B, PWR);
    }
      
    //REFLECT_1 detects black, REFLECT_2 detects white -> Turn right
    if (getSensor(REFLECT_1) < 200 && getSensor(REFLECT_2) >= 200)
    {
      setMotor(MOTOR_A, -PWR/3.0); 
      setMotor(MOTOR_B, PWR);
      LEDnum(1);
      seeingBlack = false;
    }
    
    //REFLECT_1 detects white, REFLECT_2 detects black -> Turn left
    if (getSensor(REFLECT_1) >= 200 && getSensor(REFLECT_2) < 200 && count == 0)
    {
      setMotor(MOTOR_A, -PWR);
      setMotor(MOTOR_B, PWR/3.0); 
      LEDnum(0);
      seeingBlack = false;
    }
    
    if(getSensor(REFLECT_1) < 200 && getSensor(REFLECT_2) < 200)
    {
        
    	setMotor(MOTOR_A, -PWR/3.0); 
     	setMotor(MOTOR_B, PWR);
        if (!seeingBlack)
          count++;
        seeingBlack = true;    
    } 
  }
}

//B End 3
void main()
{
	initialize();
	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
  	
  	while (getSensor(BUTTON) != 1);
  	while (getSensor(BUTTON) == 1);  
  	
  	stayOnTrack(PWR); // alter: after both sensors are black twice, go forward and exit function
  	
  	setMotor(MOTOR_A,-PWR);
	setMotor(MOTOR_B,PWR/2);
  	
        
	while(getSensor(BUMPER) == 0);

	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
  		  	
}
