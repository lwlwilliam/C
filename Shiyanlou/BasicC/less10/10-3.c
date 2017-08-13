#include<stdio.h>

int main()
{
	void swap(int *point_1, int *point_2);
	int *p1, *p2, *p, a, b;
	printf("please enter two integer number: ");
	scanf("%d, %d", &a, &b);
	p1 = &a;
	p2 = &b;
	if (a < b) {
		swap(p1, p2);
	}

	printf("max = %d, min = %d\n", a, b);
	return 0;
}

void swap(int *point_1, int *point_2)
{
	int temp;
	temp = *point_1;
	*point_1 = *point_2;
	*point_2 = temp;
}
