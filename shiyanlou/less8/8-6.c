#include<stdio.h>
#include<string.h>

int main()
{
	char str1[30] = "People's Rupulic of ";
	char str2[] = "China";
	printf("%s\n%s\n%s\n", str1, str2, strcat(str1, str2));
	return 0;
}
