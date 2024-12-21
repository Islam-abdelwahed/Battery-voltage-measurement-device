/*
 * PORT_Lcfg.c
 *
 * Created: 2/17/2024 10:49:20 PM
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
#include "PORT_Lcfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
PIN_PARAMETERS_Type PORT_Init_Pins[DEFINED_PINS] = {
	/*PIN_NUM    ,  PIN_DIR*/

	/* LED Pins*/
	{PORTB_PIN_7 , PIN_OUTPUT},
	{PORTA_PIN_4 , PIN_OUTPUT},
	{PORTA_PIN_5 , PIN_OUTPUT},
	{PORTA_PIN_6 , PIN_OUTPUT},
	/*LCD Pins*/
	{PORTA_PIN_3 , PIN_OUTPUT},
	{PORTA_PIN_2 , PIN_OUTPUT},
	{PORTB_PIN_0 , PIN_OUTPUT},
	{PORTB_PIN_1 , PIN_OUTPUT},
	{PORTB_PIN_2 , PIN_OUTPUT},
	{PORTB_PIN_4 , PIN_OUTPUT},
	/*Buzzer Pin*/
	{PORTC_PIN_6 , PIN_OUTPUT}
	/*KeyPad Pins*/
	/*{PORTC_PIN_5 ,PIN_INPUT},
	{PORTC_PIN_4 ,PIN_INPUT},
	{PORTC_PIN_3 ,PIN_INPUT},
	{PORTC_PIN_2 ,PIN_INPUT},
	{PORTD_PIN_7 ,PIN_OUTPUT},
	{PORTD_PIN_6 ,PIN_OUTPUT},
	{PORTD_PIN_5 ,PIN_OUTPUT},
	{PORTD_PIN_3 ,PIN_OUTPUT}*/

	};
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


/**********************************************************************************************************************
 *  END OF FILE:
 *********************************************************************************************************************/