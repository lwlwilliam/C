/* dyn_arr.c -- 动态分配数组 */
#include <stdio.h>
#include <stdlib.h>  /* 为 malloc()、free() 提供原型 */

int main()
{
	double* ptd;
	int max;
	int number;
	int i = 0;

	puts("What is the maximum number of type double entires?");
	if (scanf("%d", &max) != 1) {
		puts("Number not correctly entered -- bye.");
		exit(EXIT_FAILURE);
	}
	ptd = (double*) malloc(max * sizeof(double));  // 在 C 中，不一定要使用强制类型转换(double*)，但是在 C++ 中必须使用。所以，使用强制类型转换更容易把 C 程序转换为 C++ 程序。
	if (ptd == NULL) {
		puts("Memory allocation failed. Goodbye.");
		exit(EXIT_FAILURE);
	}
	/* ptd 现在指向有 max 个元素的数组 */
	puts("Enter the value (q to quit):");
	while (i < max && scanf("%lf", &ptd[i]) == 1) {
		++ i;
	}
	printf("Here are your %d entries:\n", number = i);
	for (i = 0; i < number; i ++) {
		printf("%7.2f", ptd[i]);
		if (i % 7 == 6) {
			putchar('\n');
		}
	}
	if (i % 7 != 0) {
		putchar('\n');
	}
	puts("Done.");
	free(ptd);

	return 0;
}
