
/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  DIO_Core.h
*         Created: 3/1/2024 9:23:28 PM
*         Author: @islam_elsayed
*         Module:  -
*
*  Description:  <Write File DESCRIPTION here>
*
*********************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "../../LIB/Registers.h"
#include "../../LIB/BIT_Math.h"
/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
#define DIO_PORT_A ((uint8)0U)
#define DIO_PORT_B ((uint8)1U)
#define DIO_PORT_C ((uint8)2U)
#define DIO_PORT_D ((uint8)3U)

#define DIO_PORTA_PIN0  0#define DIO_PORTA_PIN1  1#define DIO_PORTA_PIN2  2#define DIO_PORTA_PIN3  3#define DIO_PORTA_PIN4  4#define DIO_PORTA_PIN5  5#define DIO_PORTA_PIN6  6#define DIO_PORTA_PIN7  7#define DIO_PORTB_PIN0  8#define DIO_PORTB_PIN1  9#define DIO_PORTB_PIN2  10#define DIO_PORTB_PIN3  11#define DIO_PORTB_PIN4  12#define DIO_PORTB_PIN5  13#define DIO_PORTB_PIN6  14#define DIO_PORTB_PIN7  15#define DIO_PORTC_PIN0  16#define DIO_PORTC_PIN1  17#define DIO_PORTC_PIN2  18#define DIO_PORTC_PIN3  19#define DIO_PORTC_PIN4  20#define DIO_PORTC_PIN5  21#define DIO_PORTC_PIN6  22#define DIO_PORTC_PIN7  23#define DIO_PORTD_PIN0  24#define DIO_PORTD_PIN1  25#define DIO_PORTD_PIN2  26#define DIO_PORTD_PIN3  27#define DIO_PORTD_PIN4  28#define DIO_PORTD_PIN5  29#define DIO_PORTD_PIN6  30#define DIO_PORTD_PIN7  31

/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/


/**********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/
typedef enum
{
	PIN_LOW=0,
	PIN_HIGH=1
}PIN_VALUE_t;


/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/


/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
void DIO_WriteChannel(uint8 Pin_number,PIN_VALUE_t Value);
void DIO_ReadChannel(uint8 Pin_number,PIN_VALUE_t* Value);
void DIO_FlipChannel(uint8 Pin_number);
void DIO_SetPullup(uint8 Pin_number);
void DIO_WritePORTValue(uint8 port,uint8 PortValue);
void DIO_ReadPORTValue(uint8 port,uint8* PortValue);


/**********************************************************************************************************************
*  END OF FILE:
*********************************************************************************************************************/

#endif /* DIO_H_ */