#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD_CFG.h"
#include "LCD_Interface.h"
#include "Utels.h"
#define F_CPU 8000000
#include <util/delay.h>

#if LCD_MODE ==_8_Bit 


static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
 _delay_ms(50);
 WriteIns(0x38);
 WriteIns(0x0c);  //0x0e  0x0f
 WriteIns(0x01);  //clear screen
 _delay_ms(1);
 WriteIns(0x06);
  
}

#else

static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D7,READ_BIT(data,7));	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);
	WriteIns(0x0c);  //0x0e  0x0f
	WriteIns(0x01);  //clear screen
	_delay_ms(1);
	WriteIns(0x06);
	
}

#endif

void LCD_GoTo(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80+cell);
	}
	else if (line==1)
	{
		WriteIns(0x80+cell+0x40);
	}
}

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}

void LCD_WriteString(u8*str){	u8 i;		for (i=0;str[i];i++)
	{	if (i==15)
	{
		LCD_GoTo(1,0);
	
	}
		LCD_WriteChar(str[i]);
	}}void LCD_Clear(void){		WriteIns(0x01);  //clear screen		_delay_ms(2);	}void tostring(char str[], int num)
{
	int i, rem, len = 0, n;
	
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

void LCD_WriteNumber(s32 num)
{ 
	u8 x[20];
	x[0]=0;
	tostring(x,num);
	LCD_WriteString(x);
	
	
}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)?'1':'0');
	}
}


/*
void LCD_CustomChar(u8 adress,u8*pattern)
{
	WriteIns(0x4+adress*8);
	for (i=0;i<8;i++)

	{

		WriteData(pattern[i]);

	}
	
	WriteIns(0x80+adress*8);
	
}
*/
