
/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_Core.c
*        \brief
*       Created: 3/1/2024 9:22:54 PM
*       Author: @islam_elsayed
*      \details
*
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "DIO_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define DIO_TOTAL_PORT_PINS ((uint8)(8U))
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
void DIO_WriteChannel(uint8 Pin_number,PIN_VALUE_t Value){
	uint8 port=0  ,pin=0;
	
	port=Pin_number / DIO_TOTAL_PORT_PINS;
	pin=Pin_number % DIO_TOTAL_PORT_PINS;
	
	switch(Value){
		case PIN_HIGH:
		switch(port)
		{
			case DIO_PORT_A:
			Set_Bit(DIO_PORTA->PORT,pin);
			break;
			case DIO_PORT_B:
			Set_Bit(DIO_PORTB->PORT,pin);
			break;
			case DIO_PORT_C:
			Set_Bit(DIO_PORTC->PORT,pin);
			break;
			case DIO_PORT_D:
			Set_Bit(DIO_PORTD->PORT,pin);
			break;
			default:
			break;
		}
		break;
		

		case PIN_LOW:
		switch(port)
		{
			case DIO_PORT_A:
			Clr_Bit(DIO_PORTA->PORT,pin);
			break;
			case DIO_PORT_B:
			Clr_Bit(DIO_PORTB->PORT,pin);
			break;
			case DIO_PORT_C:
			Clr_Bit(DIO_PORTC->PORT,pin);
			break;
			case DIO_PORT_D:
			Clr_Bit(DIO_PORTD->PORT,pin);
			break;
			default:
			break;
		}
		break;
		
		
	}

}

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
void DIO_ReadChannel(uint8 Pin_number,PIN_VALUE_t* Value){
	uint8 port=0  , pin=0;
	
	port=Pin_number / DIO_TOTAL_PORT_PINS;
	pin=Pin_number % DIO_TOTAL_PORT_PINS;
	
	switch(port){
		case DIO_PORT_A:
		*Value = Get_Bit(DIO_PORTA->PIN,pin);
		break;
		case DIO_PORT_B:
		*Value = Get_Bit(DIO_PORTB->PIN,pin);
		break;
		case DIO_PORT_C:
		*Value = Get_Bit(DIO_PORTC->PIN,pin);
		break;
		case DIO_PORT_D:
		*Value = Get_Bit(DIO_PORTD->PIN,pin);
		break;
		default:
		break;
	}
}

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
void DIO_FlipChannel(uint8 Pin_number)
{
	uint8 port=0  ,pin=0;
	
	port=Pin_number / DIO_TOTAL_PORT_PINS;
	pin=Pin_number % DIO_TOTAL_PORT_PINS;
	
	switch(port){
		case DIO_PORT_A:
		Toggle_Bit(DIO_PORTA->PORT,pin);
		break;
		case DIO_PORT_B:
		Toggle_Bit(DIO_PORTB->PORT,pin);
		break;
		case DIO_PORT_C:
		Toggle_Bit(DIO_PORTC->PORT,pin);
		break;
		case DIO_PORT_D:
		Toggle_Bit(DIO_PORTD->PORT,pin);
		break;
		default:
		break;
	}
}

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
void DIO_SetPullup(uint8 Pin_number){
	uint8 port=0  ,pin=0;
	
	port=Pin_number / DIO_TOTAL_PORT_PINS;
	pin=Pin_number % DIO_TOTAL_PORT_PINS;
	
	switch(port)
	{
		case DIO_PORT_A:
		Set_Bit(DIO_PORTA->PORT,pin);
		break;
		case DIO_PORT_B:
		Set_Bit(DIO_PORTB->PORT,pin);
		break;
		case DIO_PORT_C:
		Set_Bit(DIO_PORTC->PORT,pin);
		break;
		case DIO_PORT_D:
		Set_Bit(DIO_PORTD->PORT,pin);
		break;
		default:
		break;
	}
}

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
void DIO_WritePORTValue(uint8 port,uint8 PortValue){
	switch(port)
	{
		case DIO_PORT_A:
		DIO_PORTA->PORT=PortValue;
		break;
		case DIO_PORT_B:
		DIO_PORTB->PORT=PortValue;
		break;
		case DIO_PORT_C:
		DIO_PORTC->PORT=PortValue;
		break;
		case DIO_PORT_D:
		DIO_PORTD->PORT=PortValue;
		break;
		default:
		break;
	}
}

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
void DIO_ReadPORTValue(uint8 port,uint8* PortValue){
	switch(port){
		case DIO_PORT_A:
		*PortValue = DIO_PORTA->PIN;
		break;
		case DIO_PORT_B:
		*PortValue = DIO_PORTB->PIN;
		break;
		case DIO_PORT_C:
		*PortValue = DIO_PORTC->PIN;
		break;
		case DIO_PORT_D:
		*PortValue = DIO_PORTD->PIN;
		break;
		default:
		break;
	}
}


/**********************************************************************************************************************
*  END OF FILE:
*********************************************************************************************************************/
