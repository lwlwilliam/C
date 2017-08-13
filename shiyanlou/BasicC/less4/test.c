#include<stdio.h>

int main()
{
	int cardnumber;
	char name[20];
	printf("Welcome to the books management system!\n");
	printf("Please input your card number: ");
	scanf("%d", &cardnumber);
	printf("Please input your name: ");
	scanf("%s", &name);
	printf("Welcome, %s! Your card number is: %d.\n", name, cardnumber);
	return 0;
}
