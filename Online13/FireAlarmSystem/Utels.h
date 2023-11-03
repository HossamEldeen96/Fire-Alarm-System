
#ifndef UTELS_H_
#define UTELS_H_



#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  CLEAR_BIT(reg,bit) (reg=reg&~(1<<bit))
#define  TOGGEL_BIT(reg,bit)  (reg=reg ^(1<<bit))


#define F_CPU 8000000
#include <util/delay.h>







#endif /* UTELS_H_ */