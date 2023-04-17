#include "LCD_config.h"
#include <LCD_interface.h>

void LCD_voidInit(void)
{
	_delay_ms(35);
	LCD_voidSendCommand(Function_Set);
	_delay_ms(40);
	LCD_voidSendCommand(DIS_ON_OFF);
	_delay_ms(1);
	LCD_voidSendCommand(CLR_LCD);
	_delay_ms(2);
	LCD_voidSendCommand(Entry_Mode);

}


void LCD_voidSendData(u8 copy_u8command)
{
	DIO_voidSetPinValue(RS,HIGH);
	DIO_voidSetPinValue(RW,LOW);
	DIO_voidSetPortValue(LCD_Data_Port,copy_u8command);
	DIO_voidSetPinValue(Enable,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(Enable,LOW);


}

void LCD_voidSendCommand(u8 copy_u8command)
{
	DIO_voidSetPinValue(RS,LOW);
	DIO_voidSetPinValue(RW,LOW);
	DIO_voidSetPortValue(LCD_Data_Port,copy_u8command);
	DIO_voidSetPinValue(Enable,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(Enable,LOW);
}