
#ifndef DURT_REG_H_
#define DURT_REG_H_

#define UCSRA    (*(volatile u8*)0x2B)
#define UCSRB    (*(volatile u8*)0x2A)
#define UCSRC    (*(volatile u8*)0x40)
#define UBRRH    (*(volatile u8*)0x40)
#define UBRRL    (*(volatile u8*)0x29)
#define UDR      (*(volatile u8*)0x2C)

/* Register UCSRB */
#define RXEN   4
#define TXEN   3
#define UCSZ2  2

/* Register UCSRA  */
#define RXC    7
#define UDRE   5

#endif /* DURT_REG_H_ */
