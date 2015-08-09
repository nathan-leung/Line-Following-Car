
#include "UW_GENE_121.h"

//All that was required for this exit was to travel in a straight line
void main()
{
	initialize();
	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
  	
  	while (getSensor(BUTTON) != 1);
  	while (getSensor(BUTTON) == 1);  
        
    while(getSensor(BUMPER)!=1) {   // due to faulty motors, this is how the car was able to drive straight
        setMotor(MOTOR_A,-50);//right
        setMotor(MOTOR_B,50);
            
        wait1Msec(350);
          
        setMotor(MOTOR_A,-50);//left
        setMotor(MOTOR_B,43);
          
    	wait1Msec(150);              
	}
	
	setMotor(MOTOR_A,0);
  	setMotor(MOTOR_B,0);
}
