#define UART3_THR    (*(volatile unsigned int *)0x49020000)
#define UART3_LSR    (*(volatile unsigned int *)0x49020014)

#define TX_FIFO_E    (1<<5)
#define RX_FIFO_E    (1<<0)

void printf(char *c);

int main(void) {
	char *c = "BOOTING...";
	printf(c);

	// Keep ourselves alive
	while (1){}

	return 0;
}

void printf(char *c){
	while (*c != '\0')
	{
		while((UART3_LSR & TX_FIFO_E) == 0);
		UART3_THR = *c;
		c++;		
	}

	// Check again and write out when done
	while((UART3_LSR & TX_FIFO_E) == 0);
	UART3_THR = '\n';
}

