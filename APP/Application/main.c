/*
* COTS.c
*
* Created: 2/9/2024 9:26:56 PM
* Author : @islam_elsayed
*/
#include "../../HAL/LCD/LCD_Core.h"
#include "../../HAL/KeyPad/KEYPAD.h"
#include "../../MCAL/ADC/ADC_Core.h"
#include "../../MCAL/PORT/PORT_Core.h"
#include "BVM_Core.h"

/***************Functions prototypes********************/
void drawCircuit(uint8* msg,uint8* unit);
uint32 getValue();
/*****************************************************/

int main(void)
{
/********************************/
	PORT_Init();
	BVM_Init();
	KEYPAD_INIT();
	LCD_Init();
/********************************/	
	
	
	while (1)
	{
		drawCircuit("Enter R1","ohm");
		
		uint32 r1=getValue();
		
		
		drawCircuit("Enter R2","ohm");
		
		uint32 r2=getValue();
		
		
		drawCircuit("Enter B v","mv");
		
		uint32 Bat_V=getValue();
		
		while(!(keypadGetValue()))
		{
			LCD_Clear();
			LCD_Goto(1,1);
			LCD_WriteString("Please Connect the");
			LCD_Goto(3,3);
			LCD_WriteString("circuit on PA7");
			_delay_ms(2000);
			LCD_Clear();
			LCD_Goto(1,2);
			LCD_WriteString("If you are ready");
			LCD_Goto(3,4);
			LCD_WriteString("Hold any Key");
			_delay_ms(2000);
		};
		
		
		
		LCD_Clear();
		LCD_Goto(1,0);
		LCD_WriteString("Calculating...");
		uint32 vin_value= BVM_GetValue( r1, r2);
		
		uint32 Bat_Health= ((float32) ( (float32) vin_value / (float32) Bat_V)) * 100;
		
		
		_delay_ms(2000);
		
		LCD_Clear();
		
		if(vin_value>500)
		{
			LCD_WriteString("calculation success");
			LCD_Goto(1,0);
			LCD_WriteString("Cap:");
			LCD_WriteInteger(vin_value);
			LCD_WriteString("mv");
			LCD_Goto(1,12);
			LCD_WriteString("Hel:");
			LCD_WriteInteger(Bat_Health);
			LCD_WriteData('%');
		}
		else
		{
		LCD_WriteString("calculation Failed:(");
		}
		
		LCD_Goto(3,2);
		LCD_WriteString("Restart in 10s");
		_delay_ms(10000);
	}
}

void drawCircuit(uint8* msg,uint8* unit)
{
	LCD_Clear();
	LCD_Goto(0,0);
	LCD_WriteString("--R---R--");
	LCD_Goto(1,0);
	LCD_WriteString("| 1   2 |");
	LCD_Goto(2,0);
	LCD_WriteString("|       |");
	LCD_Goto(3,0);
	LCD_WriteString("----|l---");
	LCD_Goto(1,11);
	LCD_WriteString(msg);
	LCD_Goto(3,11);
	LCD_WriteString(unit);
}

uint32 getValue()
{
	LCD_Goto(2,11);
	uint8 expresion[8]={0};
	uint32 resistor=0;
	uint8 cont=0;
	while(cont<8)
	{
		uint8 key=keypadGetValue();
		if(key)
		{
			BUZZER_SHORT_BEEP();
			if(key=='E')
			{
				expresion[cont]='\0';
				break;
			}
			else
			{
				LCD_WriteData(key);
				expresion[cont]=key;
				cont++;
			}
		}
	}
	
	cont=0;
	while (expresion[cont]!='\0')
	{
		resistor*=10;
		resistor+=(expresion[cont]-48);
		cont++;
	}
	return resistor;
}