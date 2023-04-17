#pragma once

void DIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction);
void DIO_voidSetPortDirection (u8 copy_u8PORT, u8 copy_u8Direction);
void DIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);
void DIO_voidSetPortValue (u8 copy_u8PORT, u8 copy_u8Value);
void DIO_voidClearPinValue (u8 copy_u8PORT, u8 copy_u8PIN);
void DIO_voidClearPortValue (u8 copy_u8PORT);
void DIO_voidTogglePinValue (u8 copy_u8PORT, u8 copy_u8PIN);
u8 DIO_voidGetPinValue (u8 copy_u8PORT, u8 copy_u8PIN);
u8 DIO_voidGetPortValue (u8 copy_u8PORT);
