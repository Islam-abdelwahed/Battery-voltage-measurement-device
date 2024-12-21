
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Buzzer_Core.c
 *        \brief  
 *       Created: 3/20/2024 3:14:47 AM
 *       Author: @islam_elsayed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Buzzer_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
	
	void BUZZER_Status(BUZZER_STATUS_Type Buz_sta){
		if (Buz_sta)
		{
			DIO_WriteChannel(BUZZER_PIN, PIN_HIGH);
			}else{
			DIO_WriteChannel(BUZZER_PIN, PIN_LOW);
		}
	};
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
	

	void BUZZER_Toggle(void){
		DIO_FlipChannel(BUZZER_PIN);
	};
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
	

	void BUZZER_SHORT_BEEP(void){
		BUZZER_Status(BUZZER_ON);
		_delay_ms(100);
		BUZZER_Status(BUZZER_OFF);
	};
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
	

	void BUZZER_LONG_BEEP(void){
		BUZZER_Status(BUZZER_ON);
		_delay_ms(1000);
		BUZZER_Status(BUZZER_OFF);
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
	

	void BUZZER_BEEP_BEEP(void){
		BUZZER_Status(BUZZER_ON);
		_delay_ms(70);
		BUZZER_Status(BUZZER_OFF);
		_delay_ms(35);
		BUZZER_Status(BUZZER_ON);
		_delay_ms(70);
		BUZZER_Status(BUZZER_OFF);
	}

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/
