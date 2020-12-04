#include <avr/io.h>

// modified example methods from AtMega88PA datasheet

void USART_Init(uint16_t baud)
{
	/* Set baud rate */
	UBRR0H  = (unsigned char) (baud >> 8);
	UBRR0L  = (unsigned char) baud;
	
	/* Enable receiver and transmitter */
	UCSR0B  = (1<<TXEN0);
	
	/* Set frame format: 8data, 1stop bit, none parity */
	UCSR0C  = (1 << UCSZ01)|(1 << UCSZ00);	
}

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A  & ( 1<< UDRE0)) );
	
	/* Put data into buffer and sends the data */
	UDR0 = data;
}