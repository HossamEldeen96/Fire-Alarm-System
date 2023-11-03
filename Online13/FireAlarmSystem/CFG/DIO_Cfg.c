

#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"
#include "StdTypes.h"


#include "DIO_Interface.h"
#include "DIO_Cfg.h"
#include "DIO_Private.h"

const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS]={
	INFREE,   /*	PORT A PIN 0 */ //LM35    TEMP      SENSOR
	OUTPUT,   /*	PORT A PIN 1 */ //LCD RS
	OUTPUT,   /*	PORT A PIN 2 */ //LCD E
	OUTPUT,   /*	PORT A PIN 3 */ //LCD D4	
	OUTPUT,   /*	PORT A PIN 4 */ //LCD D5
	OUTPUT,   /*	PORT A PIN 5 */ //LCD D6
	OUTPUT,   /*	PORT A PIN 6 */ //LCD D7
	INFREE,   /*	PORT A PIN 7 */ //MPX4115 PRESSURE  SENSOR
	INPULL,   /*	PORT B PIN 0 */
	INPULL,   /*	PORT B PIN 1 */
	INPULL,   /*	PORT B PIN 2 */
	INPULL,   /*	PORT B PIN 3 */
	OUTPUT,   /*	PORT B PIN 4 */ //A_KEYPADIN
	OUTPUT,   /*	PORT B PIN 5 */ //B_KEYPADIN
	OUTPUT,   /*	PORT B PIN 6 */ //C_KEYPADIN
	OUTPUT,   /*	PORT B PIN 7 */ //D_KEYPADIN
	OUTPUT,   /*	PORT C PIN 0 */ //FINE_LED
	OUTPUT,   /*	PORT C PIN 1 */ //FIRE_LED
	OUTPUT,   /*	PORT C PIN 2 */ //HEAT_LED
	OUTPUT,   /*	PORT C PIN 3 */
	OUTPUT,   /*	PORT C PIN 4 */
	OUTPUT,   /*	PORT C PIN 5 */
	OUTPUT,   /*	PORT C PIN 6 */
	OUTPUT,   /*	PORT C PIN 7 */
	OUTPUT,   /*	PORT D PIN 0 */ //L298 MOTOR IN1
	OUTPUT,   /*	PORT D PIN 1 */ //L298 MOTOR IN2
	INPULL,   /*	PORT D PIN 2 */ //1_KEYPADOUT  INT0
	INPULL,   /*	PORT D PIN 3 */ //2_KEYPADOUT
	INPULL,   /*	PORT D PIN 4 */ //3_KEYPADOUT
	INPULL,   /*	PORT D PIN 5 */ //4_KEYPADOUT
	INPULL,   /*	PORT D PIN 6 */
	INPULL    /*	PORT D PIN 7 */
 //TOTAL_PINS
	
	
};

