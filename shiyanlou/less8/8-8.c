#include<stdio.h>
#include<string.h>

int main()
{
	char str1[10], str2[] = "China";
	char str3[10] = {'a', 'b'}; 
	char str4[] = "Test";
	strcpy(str1, str2);
	strcpy(str3, str4);
	printf("%s\n%s\n%s\n", str1, str2, str3);
	return 0;
}
