ENTRY(main)

MEMORY
{
	ram : ORIGIN = 0x80200000, LENGTH = 0x10000
}

SECTIONS
{
	.text : { main.o(.text*)} > ram
}
