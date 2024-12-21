#include "DIO.h"

void DIO_setPortDir(uint8 port,uint8 dir){
	switch(port){
		case DIO_PORTA_:
		DDRA=dir;
		break;
		case DIO_PORTB_:
		DDRB=dir;
		break;
		case DIO_PORTC_:
		DDRC=dir;
		break;
		case DIO_PORTD_:
		DDRD=dir;
		break;
		default:
		break;
	}
};

void DIO_setPortValue(uint8 port,uint8 value){
	switch(port){
		case DIO_PORTA_:
		PORTA=value;
		break;
		case DIO_PORTB_:
		PORTB=value;
		break;
		case DIO_PORTC_:
		PORTC=value;
		break;
		case DIO_PORTD_:
		PORTD=value;
		break;
		default:
		break;
	}
};

void DIO_setPinDir(uint8 port,uint8 pin,uint8 dir){
	switch(dir){
		case DIO_PIN_OUTPUT:
		{
			switch(port){
				case DIO_PORTA_:
				Set_Bit(DDRA,pin);
				break;
				case DIO_PORTB_:
				Set_Bit(DDRB,pin);
				break;
				case DIO_PORTC_:
				Set_Bit(DDRC,pin);
				break;
				case DIO_PORTD_:
				Set_Bit(DDRD,pin);
				break;
				default:
				break;
			}
		}
		break;
		case DIO_PIN_INPUT:
		{
			switch(port){
				case DIO_PORTA_:
				Clr_Bit(DDRA,pin);
				break;
				case DIO_PORTB_:
				Clr_Bit(DDRB,pin);
				break;
				case DIO_PORTC_:
				Clr_Bit(DDRC,pin);
				break;
				case DIO_PORTD_:
				Clr_Bit(DDRD,pin);
				break;
				default:
				break;
			}
		}
		break;
		default:
		break;
	}
};

void DIO_setPullUp(uint8 port,uint8 pin){
	switch(port){
		case DIO_PORTA_:
		Set_Bit(PORTA,pin);
		break;
		case DIO_PORTB_:
		Set_Bit(PORTB,pin);
		break;
		case DIO_PORTC_:
		Set_Bit(PORTC,pin);
		break;
		case DIO_PORTD_:
		Set_Bit(PORTD,pin);
		break;
		default:
		break;
	}
	};

void DIO_setPinValue(uint8 port,uint8 pin,uint8 value){
		switch(value){
			case DIO_PIN_HIGH:
			{
				switch(port){
					case DIO_PORTA_:
					Set_Bit(PORTA,pin);
					break;
					case DIO_PORTB_:
					Set_Bit(PORTB,pin);
					break;
					case DIO_PORTC_:
					Set_Bit(PORTC,pin);
					break;
					case DIO_PORTD_:
					Set_Bit(PORTD,pin);
					break;
					default:
					break;
				}
			}
			break;
			case DIO_PIN_LOW:
			{
				switch(port){
					case DIO_PORTA_:
					Clr_Bit(PORTA,pin);
					break;
					case DIO_PORTB_:
					Clr_Bit(PORTB,pin);
					break;
					case DIO_PORTC_:
					Clr_Bit(PORTC,pin);
					break;
					case DIO_PORTD_:
					Clr_Bit(PORTD,pin);
					break;
					default:
					break;
				}
			}
			break;
			default:
			break;
		}
};

void DIO_readPinValue(uint8 port,uint8 pin,uint8* value){
	switch(port){
		case DIO_PORTA_:
		*value=Get_Bit(PINA,pin);
		break;
		case DIO_PORTB_:
		*value=Get_Bit(PINB,pin);
		break;
		case DIO_PORTC_:
		*value=Get_Bit(PINC,pin);
		break;
		case DIO_PORTD_:
		*value=Get_Bit(PIND,pin);
		break;
		default:
		break;
	}
};

void DIO_readPortValue(uint8 port,uint8* value){
	switch(port){
		case DIO_PORTA_:
		*value=PINA;
		break;
		case DIO_PORTB_:
		*value=PINB;
		break;
		case DIO_PORTC_:
		*value=PINC;
		break;
		case DIO_PORTD_:
		*value=PIND;
		break;
		default:
		break;
	}
};

void DIO_togglePin(uint8 port,uint8 pin){
	switch(port){
		case DIO_PORTA_:
		Toggle_Bit(PORTA,pin);
		break;
		case DIO_PORTB_:
		Toggle_Bit(PORTB,pin);
		break;
		case DIO_PORTC_:
		Toggle_Bit(PORTC,pin);
		break;
		case DIO_PORTD_:
		Toggle_Bit(PORTD,pin);
		break;
		default:
		break;
	}
};


