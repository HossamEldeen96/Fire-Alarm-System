#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "MOTOR_Interface.h"
#include "Keypad_Interface.h"
#include "Keypad_CFG.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"


u16 FILTER_GetFilterdTemp(void);


u16 smoke,volt,temp;
u8 flag_fine=1,flafg_heat=1,flag_SMOKE=0;
void fine(void)
{
	LCD_GoTo(0,3);
	LCD_WriteString("ALL IS Fine");
	DIO_WritePin(PINC0,HIGH);
}

u8 heat(void){
	LCD_GoTo(0,1);
	LCD_WriteString("Heat Detected");
	DIO_WritePin(PINC0,LOW);
	DIO_WritePin(PINC1,HIGH);
	DIO_WritePin(PINC2,LOW);
	while(1)
	{
		FILTER_Runnable();
		temp=FILTER_GetFilterdTemp();
		LCD_GoTo(1,2);
		LCD_WriteNumber(temp/10);
		LCD_WriteString("   ")
		if (temp<=450)
		{	MOTOR_Stop(M1);
			DIO_WritePin(PINC1,LOW);
			LCD_GoTo(0,0);
			LCD_WriteString("      ");
			return 1;
		}
		smoke=PRESS_read();
		if (smoke>=400)
		{
			LCD_GoTo(1,7);
			LCD_WriteString("Smoke%");
			smoke=PRESS_read()+3;
			LCD_WriteNumber(smoke/10);			
		}
	    if (smoke>500)
		{
			flag_SMOKE=1;
			return 0;			
		}
	}
}


void smoke_f(void)
{
	LCD_GoTo(0,1);
	LCD_WriteString("Heat Detected");
	DIO_WritePin(PINC0,LOW);
	DIO_WritePin(PINC1,LOW);
	DIO_WritePin(PINC2,HIGH);
	LCD_GoTo(1,7);
	LCD_WriteString("Smoke%");
	while (flag_SMOKE)
	{	
		LCD_GoTo(1,13);
		smoke=PRESS_read()+3;
		LCD_WriteNumber(smoke/10);
		MOTOR_CW(M1);
	}
	
	
}



int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALLER_64);
	KEYPAD_Init();
	MOTOR_Init();
	FILTER_Init();
	
	
	
	
	u8 p=0,pass=1,key[4]={0},i=0,k=NO_KEY,key_p[4]={'1','2','3','4'};
	LCD_GoTo(0,1);
	LCD_WriteString("Enter Password");
	LCD_GoTo(1,0);	
	while (pass)
	{
			k=Keypad_GetKey();
			if (k!=NO_KEY)
			{
				key[i]=k;
				LCD_WriteChar(k);
				i++;
			} 			
			if (Keypad_GetKey()=='=')
			{
				for (i=0;i<=3;i++)
				{
					if (key[i]==key_p[i])
					{
						p++;
					}
					else
					{
						p=0;
						i=3;				
					}					
				}
				if (p>=3)
				{  
					pass=0;
				} 
				else
				{   LCD_GoTo(1,3);
					LCD_WriteString(" wrong Pass!!");
					_delay_ms(2500);
					i=0;
				}
			}
					
	}
	
	LCD_GoTo(1,0);
	LCD_WriteString("T=");
	while(1)
	{
		FILTER_Runnable();
		temp=FILTER_GetFilterdTemp();
		LCD_GoTo(1,2);
		LCD_WriteNumber(temp/10);
		
		if (temp<500 && flag_fine)
		{
			fine();	
		}
		if (temp>500)
		{flag_fine=heat();
		}
		if (flag_SMOKE)
		{
			smoke_f();
		}
	}
	
	
}
	
	
	


	
	

		
					

