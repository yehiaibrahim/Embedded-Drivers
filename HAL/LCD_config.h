#pragma once

#define LCD_Data_Port          DIO_PORTA
#define RS                     DIO_PORTD,PIN0
#define RW					   DIO_PORTD,PIN1
#define Enable				   DIO_PORTD,PIN2

#define	Function_Set		   0b00111000
#define DIS_ON_OFF			   0b00001111
#define CLR_LCD				   0b00000001
#define Entry_Mode			   0b00000110
