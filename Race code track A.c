#include "UW_GENE_121.h"

const int PWR = 50;

// line following function (black line on white ground)
void stayOnTrack (int PWR) // PWR is the desired power for the motors
{
  setMotor(MOTOR_A, -PWR);
  setMotor(MOTOR_B, PWR);
  
  LEDnum(0);
  while(getSensor(BUMPER) == 0) // make sure it hasn't crashed
  {
    //Both sensors detect white -> Go straight
    while (getSensor(REFLECT_1) >= 200 && getSensor(REFLECT_2) >= 200
           && getSensor(BUMPER) == 0)
    {
      
      setMotor(MOTOR_A, -PWR);
      setMotor(MOTOR_B, PWR);
      LEDnum(7);
    }
      
    //REFLECT_1 detects black, REFLECT_2 detects white -> Pivot right
    if (getSensor(REFLECT_1) < 200 && getSensor(REFLECT_2) >= 200)
    {
      setMotor(MOTOR_A, PWR); 
      setMotor(MOTOR_B, PWR);
      LEDnum(1);
    }
    
    //REFLECT_1 detects white, REFLECT_2 detects black -> Turn left
    if (getSensor(REFLECT_1) >= 200 && getSensor(REFLECT_2) < 200)
    {
      setMotor(MOTOR_A, -PWR);
      setMotor(MOTOR_B, PWR / 1.5); 
      LEDnum(0);
    }
   
    //Both detect black -> Pivot Right
    if(getSensor(REFLECT_1) < 200 && getSensor(REFLECT_2) < 200)
    {
    	setMotor(MOTOR_A, PWR); 
     	setMotor(MOTOR_B, PWR);
			
    }
    wait1Msec(10);

    
  }
}

//A end 4

void main()
{
	initialize();
	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
  	
  	while (getSensor(BUTTON) != 1);
  	while (getSensor(BUTTON) == 1);  

	setMotor(MOTOR_A,-31);//This is to go straight
  	setMotor(MOTOR_B,28);
	  
	wait1Msec(1000);
	
	while(getSensor(REFLECT_1) >= 200 && getSensor(REFLECT_2) >= 200);
	
	stayOnTrack(50); //alter to turn right
	
	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
}
