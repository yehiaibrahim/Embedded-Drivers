#pragma once
#include <avr/io.h>			



void SPI_Init(void)
{
	DDRB |=(1<<MOSI) |(1<<SCK) |(1<<SS);
	DDRB &=~ (1<<MISO);

	PORTB |= (1<<SS);

}
