


#ifndef LCD_CFG_H_
#define LCD_CFG_H_



#define _8_Bit 1
#define _4_Bit 0

/******************_8_Bit Or _4_Bit *******************/

#define LCD_MODE _4_Bit

#define RS PINA1
#define EN PINA2

/***************** Only for _4BIT *********************/

#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6


/***************** Only for _8BIT *********************/
#define LCD_PORT PA



#endif /* LCD_CFG_H_ */