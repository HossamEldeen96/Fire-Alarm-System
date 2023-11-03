#include "StdTypes.h"
#include "ADC_Interface.h"
#include "Sensors_CFG.h"
#include "Sensors_Interface.h"
#include "LCD_Interface.h"

u16 TEMP_Read(void)
{
	u16 volt=ADC_voltRaed(LM35_CH);
	u16 temp=volt;
	return temp;
}

u16 interpolation(u16 Y_max,u16 Y_min,u16 X_max,u16 X_min,u16 ADC_Read)
{
	u16 Y,y,x;
	y=Y_max-Y_min;
	x=X_max-X_min;
	
	Y=((y*(u32)(ADC_Read-X_min))/x)+Y_min;
	return Y;
}


u16 PRESS_read()
{
	u16 adc=ADC_Read(MPX4115_CH);
	
	u16 press=interpolation(1150,150,976,55,adc);
	//press=((((u32)1000*adc)-55000)/921)+150;
	return press;
	
}