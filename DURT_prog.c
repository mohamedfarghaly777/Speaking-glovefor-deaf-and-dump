
#include "LIB/STD_TYPES.h"
#include "DURT_int.h"
#include "DURT_reg.h"
#include "LIB/BIT_MATH.h"

void UART_vidInit(void)
{
	/* Set RX , TX and Error Flags to Zero*/
	/* Set U2X to Zero */
	UCSRA = 0;

	/* Enable Receive */
	SET_BIT(UCSRB,RXEN);
	/* Transmission Enable */
	SET_BIT(UCSRB,TXEN);
	/* Set UCSZ2 to select 8-bit Data */
	CLR_BIT(UCSRB,UCSZ2);

	/* Set bit URSEL to enable Write on UCSRC */
	/* Clear bit UMSEL to set Async mode */
	/* Clear bits UPM1:0 to select no Parity */
	/* Clear USBS bi to select 1-Stop bit */
	UCSRC = 0b10000110;

	/* Set baud rate to 9600 at 12M */
	UBRRH = 0;
	UBRRL = 77;
}

void UART_vidSendChar(u8 u8DataSend)
{
	/* Wait till TX buffer is Empty */
	while(GET_BIT(UCSRA,UDRE) == 0);
	/* Set Data Register with Data to send */
	UDR = u8DataSend;
}

u8 UART_u8GetChar(void)
{
	/* Wait till a valid byte available in the RX buffer */
	while(GET_BIT(UCSRA,RXC) == 0);
	/* Return the data received */
	return UDR;
}
