/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LCD.c
*        \brief
*       Created: 3/2/2024 9:41:06 PM
*       Author: @islam_elsayed
*      \details
*
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "LCD_Core.h"
#define F_CPU 16000000
#include <util/delay.h>
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
void LCD_Init(void)
{
	#if LCD_OPERATION_MODE == LCD_4BIT_MODE
	
	/*4 Bit Mode Commands*/
	LCD_WriteCmd(0x33);
	LCD_WriteCmd(0x32);
	LCD_WriteCmd(0x28);
	/*Cursor off Command*/
	LCD_WriteCmd(0x0C);
	/*LCD Clear Command*/
	LCD_WriteCmd(0x01);
	/*Cursor Left to Right Command*/
	LCD_WriteCmd(0x06);
	/*Return Home Command*/
	LCD_WriteCmd(0x02);
	
	#elif LCD_OPERATION_MODE == LCD_8BIT_MODE
	
	/*8 Bit Mode Commands*/
	LCD_WriteCmd(0x38);
	/*Cursor off Command*/
	LCD_WriteCmd(0x0C);
	/*LCD Clear Command*/
	LCD_WriteCmd(0x01);
	/*Cursor Left to Right Command*/
	LCD_WriteCmd(0x06);
	/*Return Home Command*/
	LCD_WriteCmd(0x02);
	
	#endif /*LCD_OPERATION_MODE == LCD_4BIT_MODE*/
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
void LCD_WriteCmd(uint8 cmd)
{
	/*Select Command register*/
	DIO_WriteChannel(RS_PIN , PIN_LOW);
	/*Default low on E Pin*/
	DIO_WriteChannel(E_PIN , PIN_LOW);

	DIO_WriteChannel(D4_PIN , Get_Bit(cmd , 4 ) );
	DIO_WriteChannel(D5_PIN , Get_Bit(cmd , 5 ) );
	DIO_WriteChannel(D6_PIN , Get_Bit(cmd , 6 ) );
	DIO_WriteChannel(D7_PIN , Get_Bit(cmd , 7 ) );
	//DIO_WritePORTValue(D4_PIN , ( (cmd >> 4) & 0x07) |( (cmd>>3) & 0x10))
	
	
	/*Enable E Pin for 1 ms*/
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , Get_Bit(cmd , 0 ) );
	DIO_WriteChannel(D5_PIN , Get_Bit(cmd , 1 ) );
	DIO_WriteChannel(D6_PIN , Get_Bit(cmd , 2 ) );
	DIO_WriteChannel(D7_PIN , Get_Bit(cmd , 3 ) );
	//DIO_WritePORTValue(D4_PIN , (cmd & 0x07) |( (cmd<<1) & 0x10));
	
	
	/*Enable E Pin for 1 ms*/
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	/*Delay for 5 ms because LCD's CPU is slow */
	_delay_ms(5);
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
void LCD_WriteData(uint8 data)
{
	/*Select Data register*/
	DIO_WriteChannel(RS_PIN , PIN_HIGH);
	/*Default low on E Pin*/
	DIO_WriteChannel(E_PIN , PIN_LOW);

	DIO_WriteChannel(D4_PIN , Get_Bit(data , 4 ) );
	DIO_WriteChannel(D5_PIN , Get_Bit(data , 5 ) );
	DIO_WriteChannel(D6_PIN , Get_Bit(data , 6 ) );
	DIO_WriteChannel(D7_PIN , Get_Bit(data , 7 ) );
	//DIO_WritePORTValue(D4_PIN , ( (data >> 4) & 0x07) |( (data>>3) & 0x10))
	
	
	/*Enable E Pin for 1 ms*/
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	DIO_WriteChannel(D4_PIN , Get_Bit(data , 0 ) );
	DIO_WriteChannel(D5_PIN , Get_Bit(data , 1 ) );
	DIO_WriteChannel(D6_PIN , Get_Bit(data , 2 ) );
	DIO_WriteChannel(D7_PIN , Get_Bit(data , 3 ) );
	//DIO_WritePORTValue(D4_PIN , (data & 0x07) |( (data<<1) & 0x10));
	
	
	/*Enable E Pin for 1 ms*/
	DIO_WriteChannel(E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(E_PIN , PIN_LOW);
	
	/*Delay for 5 ms because LCD's CPU is slow */
	_delay_ms(5);
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
void LCD_WriteString(uint8* str)
{
	uint8 cnt = 0;
	
	while(str[cnt] != '\0')
	{
		LCD_WriteData(str[cnt]);
		cnt++;
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
void LCD_WriteInteger(sint32 intgr)
{
		sint32 y=1;
		if(intgr<0){
			LCD_WriteData('-');
			intgr*=-1;
		}
		while(intgr>0)
		{
			y=((y*10)+(intgr%10));
			intgr/=10;
		}
		
		while(y>1){
			LCD_WriteData(((y%10)+48));
			y/=10;
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
void LCD_Goto(uint8 Row , uint8 Col)
{
	uint8 pos[4]={0x80,0xC0,0x94,0xD4};
	LCD_WriteCmd(pos[Row]+Col);
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
void LCD_Clear(void)
{
	/*LCD Clear*/
	LCD_WriteCmd(0x01);
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
void LCD_WriteCustomChar(void)
{
	uint8 CustChar_RowLoc = 0;
	uint8 CustChar_ColLoc = 0;
	
	/*goto address 0 in CGRAM*/
	LCD_WriteCmd(0X40);
	
	for(CustChar_RowLoc = 0 ; CustChar_RowLoc < 8 ; CustChar_RowLoc++)
	{
		for(CustChar_ColLoc = 0 ; CustChar_ColLoc < 8 ; CustChar_ColLoc++)
		{
			LCD_WriteData(LCD_CUSTOM_CHARACTERS_g[CustChar_RowLoc][CustChar_ColLoc]);
		}
	}
}

/**********************************************************************************************************************
*  END OF FILE:
*********************************************************************************************************************/
