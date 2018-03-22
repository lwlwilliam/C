// wordcnt.c -- 统计字符数、单词数、行数
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'
int main(void)
{
	char c;
	char prev;
	long n_chars = 0L;
	int n_lines = 0;
	int n_words = 0;
	int p_lines = 0;
	bool inword = false;

	printf("Enter text to be analyzed (| to terminate):\n");
	prev = '\n';

	/* 没有遇到停止字符 */
	while ((c = getchar()) != STOP) {
	    /* 字符数递增 */
		n_chars ++;

		/* 遇到换行符 */
		if (c == '\n')
			n_lines ++;

	    /* 遇到非空白字符且前一个字符不在单词里 */
		if (!isspace(c) && !inword) {
			inword = true;
			n_words ++;
		}

		/* 遇到空白符并且前一个字符还在单词里 */
		if (isspace(c) && inword)
			inword = false;

		// 前一个字符
		prev = c;
	}

	// 最后的非停止字符不是换行符，算是不完整的行
	if (prev != '\n')
		p_lines = 1;
	printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
	printf("partial lines = %d\n", p_lines);

	return 0;
}
