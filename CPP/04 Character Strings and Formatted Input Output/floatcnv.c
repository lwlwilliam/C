/* floatcnv.c -- 不匹配的浮点型转换 */
#include <stdio.h>
int main(void)
{
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234566780;

	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%1d %1d\n", n3, n4);
	printf("%1d %1d %1d %1d\n", n1, n2, n3, n4);

	return 0;
}