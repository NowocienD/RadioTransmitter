
#ifndef UART_H_
#define UART_H_

# define F_CPU 1000000UL
#define BAUD 2400
#define MYUBRR ((F_CPU+BAUD*8UL) / (16UL*BAUD)-1)

void USART_Init( uint16_t );   
void USART_Transmit( uint8_t );

#endif