#include<stdio.h>

int main()
{
	float radius, diameter;
	float circumference, area;
	float pi = 3.1415926;

	printf("Input the diameter of the table: ");
	scanf("%f", &diameter);

	radius = diameter / 2.0; // 关径 = 直径 / 2.0
	circumference = 2.0 * pi * radius; // 周长 = 2.0 * pi * 半径
	area = pi * radius * radius; // 面积 = pi * 半径 * 半径

	printf("The circumference is %f\n", circumference);
	printf("The area is %f\n", area);
	
	return 0;
}
