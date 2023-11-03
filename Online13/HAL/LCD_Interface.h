
#ifndef LCD_INTERFACE_H_
#define LCD_INTE

typedef enum{
	line1,
	line2	
	}line; 

/**line 0:1 cell 0:15 **/void LCD_GoTo(u8 line,u8 cell);void LCD_Clear(void);void LCD_WriteString(u8*str);void LCD_WriteNumber(s32 num);void LCD_WriteBinary(u8 num);void LCD_WriteHex(u8 num);void LCD_WriteChar(u8 ch);void LCD_CustomChar(u8 adress,u8*patter);


#endif /* LCD_INTERFACE_H_ */