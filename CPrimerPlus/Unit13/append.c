/* append.c -- 把文件附加到另一个文件末尾 */
/*
    设计方案：
    1. 询问目标文件的名称并打开它
    2. 使用一个循环询问源文件
    3. 以读模式依次打开每个源文件，并将其添加到目标文件的末尾

    为演示 setvbuf() 的用法，该程序将使用它指定一个不同的缓冲区大小。
    下一步是细化程序打开目录文件的步骤：
    1. 以附加模式打开目标文件
    2. 如果打开失败，则退出程序
    3. 为该文件创建一个 4096 字节的缓冲区
    4. 如果创建失败，则退出程序

    与此类似，通过以下具体步骤细化拷贝部分：
    1. 如果该文件与目标文件相同，则跳至下一个文件
    2. 如果以读模式无法打开文件，则跳至下一个文件
    3. 把文件内容添加至目标文件末尾

    最后，程序回到目标文件的开始处，显示当前整个文件的内容。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main()
{
    FILE *fa, *fs;  // fa 指向目标文件，fs 指向源文件
    int files = 0;  // 附加的文件数量
    char file_app[SLEN];  // 目标文件名
    char file_src[SLEN];  // 源文件名
    int ch;

    puts("Enter name of destination file:");  // 目标文件名，被写入的文件
    s_gets(file_app, SLEN);  // 获取用户输入的目标文件名

    // 打开目标文件失败
    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    // 创建缓冲区
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 源文件名
    puts("Enter name of first source file (empty line to quit):");

    // 获取源文件名
    while (s_gets(file_src, SLEN) && file_src[0] != '\0') {
        // 防止程序把文件附加在自身末尾
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);

        // 打开源文件失败
        } else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", file_src);

        } else {
            // 创建缓冲区
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }

            // 把源文件内容写入目标文件
            append(fs, fa);

            if (ferror(fs) != 0) {
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            }
            if (ferror(fa) != 0) {
                fprintf(stderr, "Error in writinig file %s.\n", file_app);
            }
            fclose(fs);

            // 写入了一个源文件的内容
            files ++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);

    // 输出目标文件内容
    while ((ch = getc(fa)) != EOF) {
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

// 把源文件内容写入到目标文件中
void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];  // 只分配一次，无链接的静态变量

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

// 获取指定长度的输入字符串，并把该字符串赋给 st 指针
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);  // 从标准输入中获取字符串
    if (ret_val) {  // 判断是否获取成功
        find = strchr(st, '\n');  // 查找字符串中的换行符
        if (find) {
            *find = '\0';  // 把换行符替换为空字符
        } else {
            while (getchar() != '\n') {  // 忽略剩余字符
                continue;
            }
        }
    }

    return ret_val;
}
