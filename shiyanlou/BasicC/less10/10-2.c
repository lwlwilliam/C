#include<stdio.h>

int main()
{
	int *p1, *p2, *p, a, b;
	printf("please enter two integer number: ");
	scanf("%d, %d", &a, &b);
	p1 = &a;
	p2 = &b;
	if (a < b) {
		p = p1;
		p1 = p2;
		p2 = p;
		// 其实可以把这个代码块改成：p1 = &b, p2 = &a，这样就不需要定义中间变量，使得程序更加简洁
	}

	printf("a = %d, b = %d\n", a, b);
	printf("max = %d, min = %d\n", *p1, *p2);
	printf("p1 = %ld\np2 = %ld\n", p1, p2);
	return 0;
}
