#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"

void DIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction)
{
	if (1 == copy_u8Direction)
	{
		switch (copy_u8PORT)
		{
			case 0 : SET_BIT(DDRA,u8 copy_u8PIN); break;
			case 1 : SET_BIT(DDRB,u8 copy_u8PIN); break;
			case 2 : SET_BIT(DDRC,u8 copy_u8PIN); break;
			case 3 : SET_BIT(DDRD,u8 copy_u8PIN); break;
		}
	}
	else if (0 == copy_u8Direction)
	{
		switch (copy_u8PORT)
		{
			case 0 : CLR_BIT(DDRA,u8 copy_u8PIN);break;
			case 1 : CLR_BIT(DDRB,u8 copy_u8PIN);break; 
			case 2 : CLR_BIT(DDRC,u8 copy_u8PIN);break;
			case 3 : CLR_BIT(DDRD,u8 copy_u8PIN);break;
		}
	}
}

void DIO_voidSetPortDirection (u8 copy_u8PORT, u8 copy_u8Direction)
{

	switch (copy_u8PORT)
	{
		case 0 : DDRA = 0xFF; break;
		case 1 : DDRB = 0xFF; break;
		case 2 : DDRC = 0xFF; break;
		case 3 : DDRD = 0xFF; break;
	}

}
void DIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	if (1 == copy_u8Value)
	{
		switch (copy_u8PORT)
		{
			case 0 : SET_BIT(PORTA,u8 copy_u8PIN); break;
			case 1 : SET_BIT(PORTB,u8 copy_u8PIN); break;
			case 2 : SET_BIT(PORTC,u8 copy_u8PIN); break;
			case 3 : SET_BIT(PORTD,u8 copy_u8PIN); break;
		}
	}
	else if (0 == copy_u8Direction)
	{
		switch (copy_u8PORT)
		{
			case 0 : CLR_BIT(PORTA,u8 copy_u8PIN);break;
			case 1 : CLR_BIT(PORTB,u8 copy_u8PIN);break; 
			case 2 : CLR_BIT(PORTC,u8 copy_u8PIN);break;
			case 3 : CLR_BIT(PORTD,u8 copy_u8PIN);break;
		}
	}
}


void DIO_voidSetPortValue (u8 copy_u8PORT, u8 copy_u8Value)
{

	switch (copy_u8PORT)
	{
		case 0 : PORTA = 0xFF; break;
		case 1 : PORTB = 0xFF; break;
		case 2 : PORTC = 0xFF; break;
		case 3 : PORTD = 0xFF; break;
	}

}

void DIO_voidClearPinValue (u8 copy_u8PORT, u8 copy_u8PIN)
{
	switch (copy_u8PORT)
	{
		case 0 : CLR_BIT(PORTA,u8 copy_u8PIN);break;
		case 1 : CLR_BIT(PORTB,u8 copy_u8PIN);break; 
		case 2 : CLR_BIT(PORTC,u8 copy_u8PIN);break;
		case 3 : CLR_BIT(PORTD,u8 copy_u8PIN);break;
	}
}

void DIO_voidClearPortValue (u8 copy_u8PORT)
{
	switch (copy_u8PORT)
	{
		case 0 : DDRA = 0x00;break;
		case 1 : DDRB = 0x00;break;
		case 2 : DDRC = 0x00;break;
		case 3 : DDRD = 0x00;break;
	}
}

void DIO_voidTogglePinValue(u8 copy_u8PORT, u8 copy_u8PIN);
{
	switch (copy_u8PORT)
	{
		case 0 : TOG_BIT(PORTA,u8 copy_u8PIN);break;
		case 1 : TOG_BIT(PORTB,u8 copy_u8PIN);break; 
		case 2 : TOG_BIT(PORTC,u8 copy_u8PIN);break;
		case 3 : TOG_BIT(PORTD,u8 copy_u8PIN);break;
	}
}

u8 DIO_voidGetPinValue (u8 copy_u8PORT, u8 copy_u8PIN)

{
	u8 loc_result = 0;
	switch (copy_u8PORT)
	{
		case 0 : loc_result = GET_BIT(PINA,u8 copy_u8PIN);break;
		case 1 : loc_result = GET_BIT(PINB,u8 copy_u8PIN);break; 
		case 2 : loc_result = GET_BIT(PINC,u8 copy_u8PIN);break;
		case 3 : loc_result = GET_BIT(PIND,u8 copy_u8PIN);break;
	}

	return loc_result;
}

u8 DIO_voidGetPinValue (u8 copy_u8PORT)
{
	u8 loc_result = 0;
	switch (copy_u8PORT)
	{
		case 0 : loc_result = PORTA;break;
		case 1 : loc_result = PORTB;break; 
		case 2 : loc_result = PORTC;break;
		case 3 : loc_result = PORTD;break;
	}

	return loc_result;
}
