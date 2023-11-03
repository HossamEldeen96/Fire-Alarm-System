#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"
#include "ADC_Interface.h"

typedef unsigned long  u32;

#define F_CPU 8000000
#include <util/delay.h>

static u8 ADC_BusyFlag=0;





 void ADC_Init(ADC_VoltRef_type vref, ADC_Prescaller_type scaller)
 {
	 /*vref*/
	 switch(vref)
	 {
		 case VREF_AREF:
		 CLEAR_BIT(ADMUX,REFS0);
		 CLEAR_BIT(ADMUX,REFS1);
		 break;
		 case VREF_AVCC:
		 SET_BIT(ADMUX,REFS0);
		 CLEAR_BIT(ADMUX,REFS1);
		 break;
		 case VREF_256V:
		 SET_BIT(ADMUX,REFS0);
		 SET_BIT(ADMUX,REFS1);
		 break;
	 }
	 
	 
	 /*prescaller*/
	 ADCSRA&=0XF8;
	 scaller&=0x07;
	 ADCSRA=ADCSRA|scaller;	  
	 /*Enable ADC*/
	 SET_BIT(ADCSRA,ADEN);
	 
	 
	 
 }
 
 u16 ADC_Read(ADC_Channel_type CH )
 {	
	 
	 /* set channel mux*/
	 ADMUX=ADMUX&0xE0;  //11100000;

	 ADMUX|=CH;
	 
	 	 
	 /*start conversion*/
	 SET_BIT(ADCSRA,ADSC);
	 /*w8 ADC finish Busy waite (Bloking)*/
	 while(READ_BIT(ADCSRA,ADSC));
	  /*get read*/
	  /*u16 ADC_data=0;*/
// 	  ADC_data=(ADCH<<8);
// 	  ADC_data=ADC_data|ADCL;

	  return ADC;
	  
	 
 }
 
 void ADC_StartConversion(ADC_Channel_type CH)
 {	
	 if (ADC_BusyFlag==0)
	 {
		  /* set channel mux*/
		  ADMUX=ADMUX&0xE0;  //11100000;
		  ADMUX|=CH;
		  
		  /*start conversion*/
		  SET_BIT(ADCSRA,ADSC);
		  ADC_BusyFlag=1;
		  
	 }
	 
 }
 u16 ADC_GetRead(void)
 {
	   /*get read*/
	   /*u16 ADC_data=0;*/
	   // 	  ADC_data=(ADCH<<8);
	   // 	  ADC_data=ADC_data|ADCL;
	   /*w8 ADC finish Busy waite (Bloking)*/
	   while(READ_BIT(ADCSRA,ADSC));
	   return ADC;
 }
 
 u8 ADC_GetReadPeriodic(u16* pdata)
 {
	 /*Periodec Chek (Polling)*/
	 if (READ_BIT(ADCSRA,ADSC))
	 {
		 *pdata=ADC;
		 ADC_BusyFlag=0;
		 return 1;
	 }
	 return 0;
 }
 
 u16 ADC_GetReadNoblock(void)
 {
	 return ADC;
 }
 
 u16 ADC_voltRaed(ADC_Channel_type CH)
 {
	 u16 adc_=ADC_Read(CH);
	 u16 volt;
	 volt=(adc_*(u32)5000)/1024;

	 return volt;
 }