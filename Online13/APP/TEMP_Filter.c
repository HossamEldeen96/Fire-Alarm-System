#include "StdTypes.h"
#include "Sensors_Interface.h"


#define F_CPU 8000000
#include <util/delay.h>


u16 main[10],filteredTemp=0,unfilteredTemp,flag=1,i=0;
void FILTER_Init(void)
{
	main[0]=TEMP_Read();	
	
}

/*Not more than 200us*/
void FILTER_Runnable(void)
{
	for (;flag;i++)
	{	unfilteredTemp=TEMP_Read();
		main[i]=unfilteredTemp;
		
		flag=0;
	}
	flag=1;
	//_delay_ms(250);
	if (i==9)
	{	for (i=0;i<=9;i++)
		{
			filteredTemp+=main[i];
		}
	
		filteredTemp=filteredTemp/10;
		i=0;
	}
	
}

u16 FILTER_GetFilterdTemp(void)
{
	return filteredTemp;
	}
u16 FILTER_GetUnFilterdTemp(void)
{	
	return unfilteredTemp;	
}