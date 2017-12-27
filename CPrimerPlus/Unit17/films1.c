/* films1.c -- 使用一个结构数组 */
#include <stdio.h>
#include <string.h>
#include "head.h"
#define TSIZE 45  /* 储存片名的数组大小 */
#define FMAX   5  /* 影片的最大数量 */

struct film {
    char title[TSIZE];
    int rating;
};

int main(void)
{
    struct film movies[FMAX];  // 定义一个数组保存所有影片，数组元素类型为 film 结构
    int i = 0;
    int j;

    puts("Enter first movie title: ");
           // 影片数量在限定范围内 且 影片名不为空 且 影片名首字符中为空字符
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0') {
        puts("Enter you rating <0~10>: ");
        scanf("%d", &movies[i ++].rating);

        // 去除输入行剩余部分
        while (getchar() != '\n') {
            continue;
        }
        puts("Enter next movie title (empty line to stop): ");
    }

    // 判断是否有影片信息
    if (i == 0) {
        printf("No data entered.");
    } else {
        printf("Here is the movie list:\n");
    }

    // 列出所有输入的影片
    for (j = 0; j < i; j ++) {
        printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
    }

    printf("Bye.\n");

    return 0;
}
