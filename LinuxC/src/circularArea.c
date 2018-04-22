#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	double dsquared = dx * dx + dy * dy;
	double result = sqrt(dsquared);

	return result;
}

double area(double radius)
{
	return 3.1416 * radius * radius;
}

double area_point(double x1, double y1, double x2, double y2)
{
	return area(distance(x1, y1, x2, y2));
}

int main(void)
{
	printf("distance is %f\n", distance(1.0, 2.0, 4.0, 6.0));
	printf("area is %f\n", area_point(1.0, 2.0, 4.0, 6.0));

	return 0;
}
