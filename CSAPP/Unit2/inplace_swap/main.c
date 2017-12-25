#include <stdio.h>
#include "head.h"

int main()
{
    int len;

    printf("Please enter the length of array: ");
    scanf("%d", &len);

    int arr[len];
    int val;
    int i;

    printf("Please enter one digit: ");
    for (i = 0; i < len; i ++) {
        if (scanf("%d", &arr[i]) && i != len - 1) {
            printf("Please enter one digit: ");
        }
    }

    reverse_array(arr, len);

    for (i = 0; i < len; i ++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}