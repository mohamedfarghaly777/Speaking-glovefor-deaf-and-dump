
#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Group A Regs */
#define PORTA_Reg  ((volatile u8*)0x3B)
#define DDRA_Reg   ((volatile u8*)0x3A)
#define PINA_Reg   ((volatile u8*)0x39)

/* Group B Regs */
#define PORTB_Reg  ((volatile u8*)0x38)
#define DDRB_Reg   ((volatile u8*)0x37)
#define PINB_Reg   ((volatile u8*)0x36)

/* Group C Regs */
#define PORTC_Reg  ((volatile u8*)0x35)
#define DDRC_Reg   ((volatile u8*)0x34)
#define PINC_Reg   ((volatile u8*)0x33)

/* Group D Regs */
#define PORTD_Reg  ((volatile u8*)0x32)
#define DDRD_Reg   ((volatile u8*)0x31)
#define PIND_Reg   ((volatile u8*)0x30)


#endif /* DIO_REG_H_ */
