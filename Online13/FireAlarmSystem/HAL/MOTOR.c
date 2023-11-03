#include "StdTypes.h"
#include "DIO_Interface.h"
#include "MOTOR_CFG.h"
#include "MOTOR_Interface.h"

void MOTOR_Init(void)
{
	MOTOR_type i=0;
	for (i=0;i<M4;i++)
	{
		MOTOR_Stop(i);
	}

	
}

void MOTOR_Stop(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,LOW);	
		break;	
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;	
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,LOW);
		break;	
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,LOW);
		break;	
		
		
	}
}

void MOTOR_CW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,HIGH);
		DIO_WritePin(M1_IN2,LOW);
		break;	
		case M2:
		DIO_WritePin(M2_IN1,HIGH);
		DIO_WritePin(M2_IN2,LOW);
		break;	
		case M3:
		DIO_WritePin(M3_IN1,HIGH);
		DIO_WritePin(M3_IN2,LOW);
		break;	
		case M4:
		DIO_WritePin(M4_IN1,HIGH);
		DIO_WritePin(M4_IN2,LOW);
		break;	
		
		
	}
}

void MOTOR_CCW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,HIGH);
		break;	
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,HIGH);
		break;	
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,HIGH);
		break;	
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,HIGH);
		break;	
		
		
	}
}