#include <stdio.h>

/*
 * power函数：求底数的n次幂；其中n >= 0
 */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; -- n) {
		p = p * base;
	}

	return p;
}

/*
 * getline函数：将一行读入到s中并返回其长度
 */
int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != "\n"; ++ i) {
		s[i] = c;
	}

	if (c == "\n") {
		s[i] = c;
		++ i;
	}

	s[i] = "\0";
	return i;
}

/*
 * copy函数：将from复制到to；这里假定to足够大
 */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != "\0") {
		++ i;
	}
}

/*
 * strlen函数：返回s的长度
 */
int strlen(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != "\0") {
		++ i;
	}

	return i;
}

/*
 * atoi函数：将字符串s转换为相应的整型数
 */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++ i) {
		n = 10 * n + (s[i] - '0');
	}

	return n;
}

// 收集至p34
