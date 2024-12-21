
/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ADC_Core.c
*        \brief
*       Created: 3/22/2024 9:23:32 PM
*       Author: @islam_elsayed
*      \details
*
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "../../APP/Cfg/ADC_Cfg.h"
#include "ADC_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL DATA
*********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL DATA
*********************************************************************************************************************/
uint32 ADC_VinValue_mv;

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
void ADC_Init(void)
{
	
	#if		ADC_VOLTAGE_REFRENCE == ADC_VREF_AVCC
	
	Set_Bit(ADMUX,6);
	Clr_Bit(ADMUX,7);
	
	#elif	ADC_VOLTAGE_REFRENCE == ADC_VREF_AREF
	
	Clr_Bit(ADMUX,6);
	Clr_Bit(ADMUX,7);
	
	#elif	ADC_VOLTAGE_REFRENCE == ADC_VREF_INTERNAL
	
	Set_Bit(ADMUX,6);
	Set_Bit(ADMUX,7);
	
	#endif /*#if		ADC_VOLTAGE_REFRENCE == ADC_VREF_AVCC*/
	
	
	#if		ADC_CHANNEL == 	ADC_CHANNEL_0
	
	ADMUX |=0x00;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_1
	
	ADMUX |=0x01;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_2
	
	ADMUX |=0x02;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_3
	
	ADMUX |=0x03;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_4
	
	ADMUX |=0x04;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_5
	
	ADMUX |=0x05;
	
	#elif	ADC_CHANNEL == 	ADC_CHANNEL_6
	
	ADMUX |=0x06;
	
	#elif	ADC_CHANNEL ==	ADC_CHANNEL_7
	
	ADMUX |=0x07;
	
	#endif /*	#if		ADC_CHANNEL == 	ADC_CHANNEL_0*/
	
	
	#if		ADC_CONVERSION_TRIGGER == ADC_CONVERSION_SINGLE
	
	Clr_Bit(ADCSRA,5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_FREE_RUNNING
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x00 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_ANALOG_COMPARATOR
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x01 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_EXXTERNAL_INTERRUPT_0
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x02 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER0_COMPARE_MATCH
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x03 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER0_OVERFLOW
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x04 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER1_COMPARE_MATCH_B
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x05 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER1_OVERFLOW
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x06 << 5);
	
	#elif	ADC_CONVERSION_TRIGGER == ADC_CONVERSION_TIMER_CAPTURE_EVENT
	
	Set_Bit(ADCSRA,5);
	SFIOR |= (0x07 << 5);
	
	#endif /*#if		ADC_CONVERSION_TRIGGER == ADC_CONVERSION_SINGLE*/
	
	
	#if		ADC_PRESCALER == ADC_PRESCALER_2
	
	ADCSRA |= 0x01;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_4
	
	ADCSRA |= 0x02;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_8
	
	ADCSRA |= 0x03;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_16
	
	ADCSRA |= 0x04;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_32
	
	ADCSRA |= 0x05;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_64
	
	ADCSRA |= 0x06;
	
	#elif	ADC_PRESCALER == ADC_PRESCALER_128
	
	ADCSRA |= 0x07;
	
	#endif /*#if		ADC_PRESCALER == ADC_PRESCALER_2*/
	
	
	
	
	#if		ADC_INTERRUPT_STATUS == ADC_INTERRUPT_ENABLE
	
	Set_Bit(ADCSRA,3);
	
	#elif	ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLE
	
	Clr_Bit(ADCSRA,3);
	
	#endif /*#if		ADC_INTERRUPT_STATUS == ADC_INTERRUPT_ENABLE*/
	
	
	
	#if		ADC_REG_ADJUST == ADC_LEFT_ADJUST
	
	Set_Bit(ADMUX,5);
	
	#elif	ADC_REG_ADJUST == ADC_RIGHT_ADJUST
	
	Clr_Bit(ADMUX,5);
	
	#endif /*#if		ADC_REG_ADJUST == ADC_LEFT_ADJUST*/
	


	/*Enable ADC*/
	Set_Bit(ADCSRA,7);
	
	
	
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
void ADC_Read(void)
{
	uint32 ADC_DigValue;

	/*Start Conversion*/
	Set_Bit(ADCSRA , 6);

	#if (ADC_INTERRUPT_STATUS  ==  ADC_INTERRUPT_DISABLE)
	while(Get_Bit(ADCSRA , 4) == 0U);

	#if (ADC_REG_ADJUST  ==  ADC_RIGHT_ADJUST)
	ADC_DigValue = ADC_INPUT_16BIT_ACCESS;

	#elif (ADC_REG_ADJUST  ==  ADC_LEFT_ADJUST)
	ADC_DigValue = (ADCH << 2) | (ADCL >> 6);

	#endif /*End #if (ADC_ADJUST  ==  ADC_RIGHT_ADJUCT)*/

	ADC_VinValue_mv = (ADC_DigValue * ADC_VREF_VALUE) / ADC_RESOLUTION;
	#endif /* if (ADC_INTERRUPT_STATUS  ==  ADC_INTERRUPT_DISABLE)*/
}


/**********************************************************************************************************************
*  END OF FILE:
*********************************************************************************************************************/
