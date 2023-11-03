
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
	}ADC_VoltRef_type;

typedef enum{
	ADC_SCALLER_2=1,
	ADC_SCALLER_4,
	ADC_SCALLER_8,
	ADC_SCALLER_16,
	ADC_SCALLER_32,
	ADC_SCALLER_64,
	ADC_SCALLER_128,
	}ADC_Prescaller_type;
	
typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	
	}ADC_Channel_type;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaller_type scaller);

u16 ADC_Read(ADC_Channel_type CH );
u16 ADC_voltRaed(ADC_Channel_type CH);
 void ADC_StartConversion(ADC_Channel_type CH);
u16 ADC_GetRead(void);
 u16 ADC_GetReadNoblock(void);

#endif /* ADC_INTERFACE_H_ */