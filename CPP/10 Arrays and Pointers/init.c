/* 初始化二维数组的两种方法 */
#include <stdio.h>
#define ROWS 2
#define COLS 3
int main()
{
    int arr_a[ROWS][COLS] = {{1, 2}, {3, 4}};
    int arr_b[ROWS][COLS] = {1, 2, 3, 4};
    int arr_c[ROWS][COLS] = {{1, 2, 3}, {4}};
    int i, j;

    for (i = 0; i < ROWS; i ++) {
        for (j = 0; j < COLS; j ++) {
            printf("arr_a: ROWS %d, COLS %d, VALUE %d\n", i, j, arr_a[i][j]);
            printf("arr_b: ROWS %d, COLS %d, VALUE %d\n", i, j, arr_b[i][j]);
            printf("arr_c: ROWS %d, COLS %d, VALUE %d\n\n", i, j, arr_c[i][j]);
        }
    }

    return 0;
}