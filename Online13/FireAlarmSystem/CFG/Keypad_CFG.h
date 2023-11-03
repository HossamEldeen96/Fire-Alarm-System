

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define ROWS 4
#define COLS 4

#define NO_KEY '0'

#define FIRST_OUTPUT PINB4
#define FIRST_INPUT  PIND2

#ifdef KEYPAD_A 

u8 KeysArr[ROWS][COLS]= { {'7','8','9','/'}
                         ,{'4','5','6','*'}
                         ,{'1','2','3','-'}
                         ,{'C','0','=','+'}};

#endif

	
#endif /* KEYPAD_CFG_H_ */