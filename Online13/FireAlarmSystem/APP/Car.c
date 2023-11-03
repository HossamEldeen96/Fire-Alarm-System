#include "StdTypes.h"

#include "MOTOR_Interface.h"
#include "DIO_Interface.h"



#define FB PIND3
#define BB PINB5
#define LB PIND2
#define BB PINB2

static void moveBackward(void); 
static void moveforward(void) ;

void CAR_Init(void)
{
	
}

void CAR_Runnable(void)
{
	if (DIO_ReadPin(FB)==LOW)
	{
		moveforward();
	}
	if (DIO_ReadPin(BB))
	{
		moveBackward();
	}
}

static void moveforward(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
	
}
static void moveBackward(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
}