/* 初始化二维数组的两种方法 */
#include <stdio.h>

int main()
{
		// demo #1
		int sq[2][3] = {{5, 6}, {7, 8}};

		// demo #2
		int sq2[2][3] = {5, 6, 7, 8};

		int i, j;

		for (i = 0; i < 2; i ++) {
			for (j = 0; j < 3; j ++) {
				printf("sq[%d][%d] = %d\n", i, j, sq[i][j]);
				printf("sq2[%d][%d] = %d\n", i, j, sq2[i][j]);
			}
		}
}
