
#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"


#include "DIO_Interface.h"
#include "DIO_Cfg.h"
#include "DIO_Private.h" 
extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];

void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArr[i]);
		
	}
}

void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,Pin_num);
			CLEAR_BIT(PORTA,Pin_num);
			break;
			case PB:
			SET_BIT(DDRB,Pin_num);
			CLEAR_BIT(PORTB,Pin_num);
			break;
			case PC:
			SET_BIT(DDRC,Pin_num);
			CLEAR_BIT(PORTC,Pin_num);
			break;
			case PD:
			SET_BIT(DDRD,Pin_num);
			CLEAR_BIT(PORTD,Pin_num);
			break;
			
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLEAR_BIT(DDRA,Pin_num);
			CLEAR_BIT(PORTA,Pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,Pin_num);
			CLEAR_BIT(PORTB,Pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,Pin_num);
			CLEAR_BIT(PORTC,Pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,Pin_num);
			CLEAR_BIT(PORTD,Pin_num);
			break;
		}
		break;
		case INPULL:
			switch(port)
			{
				case PA:
				CLEAR_BIT(DDRA,Pin_num);
				SET_BIT(PORTA,Pin_num);
				break;
				case PB:
				CLEAR_BIT(DDRB,Pin_num);
				SET_BIT(PORTB,Pin_num);
				break;
				case PC:
				CLEAR_BIT(DDRC,Pin_num);
				SET_BIT(PORTC,Pin_num);
				break;
				case PD:
				CLEAR_BIT(DDRD,Pin_num);
				SET_BIT(PORTD,Pin_num);
				break;
			}
			break;
		
	}
}


void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
		u8 Pin_num=pin%8;
		DIO_Port_type port=pin/8;
		if (volt==HIGH)
		{
				switch(port)
				{
					case PA:				
					SET_BIT(PORTA,Pin_num);
					break;
					case PB:					
					SET_BIT(PORTB,Pin_num);
					break;
					case PC:					
					SET_BIT(PORTC,Pin_num);
					break;
					case PD:				
					SET_BIT(PORTD,Pin_num);
					break;
				}			
		} 
		else
		{
			switch(port)
			{
				case PA:				
				CLEAR_BIT(PORTA,Pin_num);
				break;
				case PB:				
				CLEAR_BIT(PORTB,Pin_num);
				break;
				case PC:				
				CLEAR_BIT(PORTC,Pin_num);
				break;
				case PD:				
				CLEAR_BIT(PORTD,Pin_num);
				break;
			}
		}
}
void DIO_WritePort(DIO_Port_type port,u8 data)  {	switch (port)	{		case PA:		PORTA = data;		break;				case PB:		PORTB = data;		break;				case PC:		PORTC = data;		break;				case PD:		PORTD = data;		break;	}}

DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,Pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,Pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,Pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,Pin_num);
		break;
	}
	return volt;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch (port)
	{
		case PA:
		TOGGEL_BIT(PORTA,Pin_num);
		break;
		case PB:
		TOGGEL_BIT(PORTB,Pin_num);
		break;
		case PC:
		TOGGEL_BIT(PORTC,Pin_num);
		break;
		case PD:
		TOGGEL_BIT(PORTD,Pin_num);
		break;
	}
	
}

