#include<stdio.h>
/*
stdin
stdout
stderr
 */

int main()
{
	// printf("please input the value a:\n");
	fprintf(stdout, "please input the value a:\n");
	int a;
	// scanf("%d", &a);
	fscanf(stdin, "%d", &a);
	if (a < 0) {
		fprintf(stderr, "the value must > 0\n");
		return 1;
	} else {
		fprintf(stdout, "the value you input is : %d\n", a);
	}
	return 0;
}
