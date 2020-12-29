
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define PortA   0
#define PortB   1
#define PortC   2
#define PortD   3

#define Pin0    0
#define Pin1    1
#define Pin2    2
#define Pin3    3
#define Pin4    4
#define Pin5    5
#define Pin6    6
#define Pin7    7

#define High    0xFF
#define Low     0x00

#define Input   0x00
#define Output  0xFF

#define INVALID_INPUT 0xFF

void DIO_vidSetPinValue(u8 u8PortId , u8 u8PinId , u8 u8PinVal);

u8   DIO_u8GetPinValue(u8 u8PortId , u8 u8PinId);

void DIO_vidSetPinDirection(u8 u8PortId , u8 u8PinId , u8 u8PinDir);

/* Port Interfaces */
void DIO_vidSetPortValue(u8 u8PortId ,u8 u8PortVal);

void DIO_vidSetPortDir(u8 u8PortId , u8 u8PortDir);

#endif /* DIO_INT_H_ */
