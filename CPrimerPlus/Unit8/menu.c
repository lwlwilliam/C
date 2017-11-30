#include <stdio.h>
char get_choice(void);
void count(void);
int main()
{
	int choice;
	while ((choice = get_choice()) != 'q') {
		switch (choice) {
			case 'a': printf("Buy low, sell high.\n");break;
			case 'b': putchar('\a');break;  /* ANSI */
			case 'c': count();break;
			default: printf("Program error!\n");break;
		}
	}

	return 0;
}

char get_choice(void)
{
	int ch;
	printf("Enter the letter of your choice: \n");
	printf("a. advice		b. bell\n");
	printf("c. count		q. quit\n");
	ch = getchar();
	while ((ch < 'a' || ch > 'c') && ch != 'q') {
		printf("Please respond with a, b, c, or q.\n");
		ch = getchar();
	}

	return ch;
}

