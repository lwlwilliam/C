#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	char buff[255];

	fp = fopen("./test.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1 : %s\n", buff); // 1 : This。fscanf()只读取了This，因为它后边遇到了一个空格。

	fgets(buff, 255, (FILE*)fp);
	printf("2 : %s\n", buff); // 2 : is testing form fprintf...

	fgets(buff, 255, (FILE*)fp);
	printf("3 : %s\n", buff); // 3 : This is testing for fputs...
	fclose(fp);
	
	return 0;
}
