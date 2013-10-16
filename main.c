#define UART3_THR    (*(volatile unsigned int *)0x49020000)
#define UART3_LSR    (*(volatile unsigned int *)0x49020014)

#define TX_FIFO_E    (1<<5)
#define RX_FIFO_E    (1<<0)

int main() {
	// Check the LSR_tx reg
	while((UART3_LSR & TX_FIFO_E) == 0)
		;
	
	// Write out something
	UART3_THR = '!';

	// Check again and write out when done
	while((UART3_LSR & TX_FIFO_E) == 0)
		;
	UART3_THR = '\n';

	return 1;
}
