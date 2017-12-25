#include <stdio.h>

int main()
{
	int a = 0x76543210;

	printf("%08x\n", a>>32);
	printf("%08x\n", a>>28);
	printf("%08x\n", a>>16);
	printf("%08x\n", a>>8);

	printf("%08x\n", 1<<2+3<<4);
	printf("%08x\n", 1<<(2+3)<<4);
	printf("%08x\n", (1<<(2+3))<<4);
	printf("%08x\n", (1<<2)+(3<<4));

	return 0;
}
