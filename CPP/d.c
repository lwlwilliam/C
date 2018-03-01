#include <stdio.h>
/**
 * 判断一个正整数是几位数
 */

int main()
{
	int x;
	int n = 0;

	scanf("%d", &x);

	while (x > 0) {
		n ++;
		x /= 10; // 去掉个位数
	}
	printf("%d\n", n);
	
	return 0;
}
