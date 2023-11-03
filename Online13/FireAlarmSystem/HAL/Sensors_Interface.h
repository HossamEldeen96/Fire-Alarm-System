
#ifndef SENSORS_INTERFACE_H_
#define SENSORS_INTERFACE_H_

u16 TEMP_Read(void);

u16 interpolation(u16 Y_max,u16 Y_min,u16 X_max,u16 X_min,u16 ADC_Read);

u16 PRESS_read();


#endif /* SENSORS_INTERFACE_H_ */