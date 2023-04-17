/******************************************************/
/* Author    :                                        */
/* Date      :                                        */
/* Version   :                                        */
/******************************************************/

/************* Header Files INCLUSIONS ****************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

/***************** KeyPad Key Index *******************/                         
/*            Col_3    Col_2   Col_1   Col_0          */
/*                                                    */
/* row_0        1        2       3       4            */
/*                                                    */
/* row_1  	    5        6       7       8            */
/*                                                    */
/* row_2	    9        10      11      12           */
/*                                                    */
/* row_3	    13       14      15      16           */
/******************************************************/

const u8 KPD_u8SwitchVal[4][4] = KPD_KEYS ;
 
 
const u8  KPD_u8RowsPins[4] ={ROW1,ROW2,ROW3,ROW4};
const  u8 KPD_u8ColsPins[4] ={COL1,COL2,COL3,COL4};


void KPD_voidInit(void)
{
	
	DIO_voidSetPinDirection(KPD_PORT,ROW1,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,ROW2,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,ROW3,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,ROW4,OUTPUT);
							
	DIO_voidSetPinDirection(KPD_PORT,COL1,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,COL2,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,COL3,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,COL4,INPUT);
	
	
	DIO_voidSetPortValue(KPD_PORT,255);
}


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8Col , Local_u8Row;
	u8 Local_u8Sw = KPD_u8KEY_NOT_PRESSED , Local_u8Flag = 0;
	
	for(Local_u8Row=0 ; Local_u8Row <= 3 ;Local_u8Row++)
	{
		DIO_voidSetPinValue(KPD_PORT,KPD_u8RowsPins[Local_u8Row],LOW);
		
		for(Local_u8Col = 0 ;Local_u8Col <= 3 ;Local_u8Col ++)
		{
			if(DIO_u8GetPinValue(KPD_PORT , KPD_u8ColsPins[Local_u8Col]) == LOW) /* switch is pressed */
			{
				
				//for bouncing
			    _delay_ms(20);
				while(DIO_u8GetPinValue(KPD_PORT , KPD_u8ColsPins[Local_u8Col])== 0);//for the delay of pressing
				

				Local_u8Sw = KPD_u8SwitchVal[Local_u8Row][Local_u8Col];
				Local_u8Flag = 1;
				break;
				
				
			}
			
		}
		DIO_voidSetPinValue(KPD_PORT,KPD_u8RowsPins[Local_u8Row],HIGH);
		if(Local_u8Flag == 1)
		{
			break;
		}
		
	}
	return Local_u8Sw;
}
