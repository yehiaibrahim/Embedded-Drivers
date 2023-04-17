#inlcude "DIO_Interface.h"
#include 

void voidSevenSegmentINIT(u8 port_name)
{
	DIO_voidSetPortDirection (port_name, oxFF);
}

void voidSevenSegmentWrite(u8 port_name, u8 number)
{
	u8 arr[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f}
	DIO_voidSetPortValue (port_name, arr[number]);
}
