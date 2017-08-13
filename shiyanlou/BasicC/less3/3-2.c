#include<stdio.h>

int main()
{
	float tank_volume; // 定义油箱容积为浮点数类型变量tank_volumn
	float oil_density; // 定义油的密度为浮点类型变量oil_density
	float oil_kg;
	float area;

	tank_volume = 0.1; // 0.1立方米
	oil_density = 850; // 850公斤每立方米
	oil_kg = tank_volume * oil_density; // 质量 = 容积 * 密度
	area = oil_kg / 0.85; // 每亩地耗油0.85kg，可耕亩数 = 油质量 / 0.85

	printf("Most farming is %f mu\n", area);
	return 0;
}
