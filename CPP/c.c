#include <stdio.h>

int main()
{
	const double RATE = 8.25;
	const int STANDARD = 40;
	double pay = 0.0;
	int hours;

	printf("please enter the hours: \n");
	scanf("%d", &hours);
	printf("\n");
	
	if (hours > STANDARD)
		pay = STANDARD * RATE + 
			(hours - STANDARD) * (RATE * 1.5);
	else 
		pay = hours * RATE;

	printf("the salary is : %f\n", pay);
	return 0;
}
