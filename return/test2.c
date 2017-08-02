#include<stdio.h>

int main(int argv, char *argc[])
{
	int i;
	printf("argv is %d\n", argv);

	for ( i = 0; i < argv; i ++) {
		printf("argc[%d] is %s\n", i, argc[i]);
	}
	return 0;
}
