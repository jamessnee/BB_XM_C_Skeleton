start.bin : main.c
	arm-none-linux-gnueabi-gcc -Wall -Werror -O3 -nostdlib -nostartfiles -ffreestanding -c main.c -o main.o
	arm-none-linux-gnueabi-ld -T linker.ld main.o -o build.elf
	arm-none-linux-gnueabi-objdump -D build.elf > build.list
	arm-none-linux-gnueabi-objcopy build.elf -O srec build.srec
	arm-none-linux-gnueabi-objcopy build.elf -O binary start.bin
