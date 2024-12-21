/*
 * PORT_Core.c
 *
 * Created: 2/17/2024 10:47:17 PM
 *  Author: @islam_elsayed
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define    PORT_A     ((uint8)0U)
#define    PORT_B     ((uint8)1U)
#define    PORT_C     ((uint8)2U)
#define    PORT_D     ((uint8)3U)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PORT_Init(void)
{
	uint8 LoopCounter = 0 , Port = 0 , Pin = 0 , Dir = 0;
	
	for(LoopCounter = 0 ;LoopCounter < DEFINED_PINS; LoopCounter++ )
	{
		Port = PORT_Init_Pins[LoopCounter].PinOrder / NUMBER_PORT_PINS ;
		Pin  = PORT_Init_Pins[LoopCounter].PinOrder % NUMBER_PORT_PINS ;
		Dir  = PORT_Init_Pins[LoopCounter].PinDir;
		
		switch(Dir)
		{
			case PIN_OUTPUT:
			switch(Port)
			{
				case PORT_A :
				Set_Bit(DIO_PORTA->DDR , Pin);
				break;
				case PORT_B :
				Set_Bit(DIO_PORTB->DDR , Pin);
				break;
				case PORT_C :
				Set_Bit(DIO_PORTC->DDR , Pin);
				break;
				case PORT_D :
				Set_Bit(DIO_PORTD->DDR , Pin);
				break;
				default:
				break;
			}
			break;
			
			case PIN_INPUT:
			switch(Port)
			{
				case PORT_A :
				Clr_Bit(DIO_PORTA->DDR , Pin);
				break;
				case PORT_B :
				Clr_Bit(DIO_PORTB->DDR , Pin);
				break;
				case PORT_C :
				Clr_Bit(DIO_PORTC->DDR , Pin);
				break;
				case PORT_D :
				Clr_Bit(DIO_PORTD->DDR , Pin);
				break;
				default:
				break;
			}
			break;
			
			default:
			break;
		}
	}
}


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/