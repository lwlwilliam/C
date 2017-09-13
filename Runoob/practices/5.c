/*
输入三个整数x,y,z，请把这三个数由小到大输出。
程序分析：想办法把最小的数放到x，先将x与y进行比较，如果x>y由将x与y的值进行交换，然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。
*/
#include <stdio.h>

int main()
{
	int x, y, z, t;
	
	printf("请输入三个数字：\n");
	scanf("%d%d%d", &x, &y, &z);
	if (x > y) {
		t = x;
		x = y;
		y = t;
	}

	if (x > z) {
		t = z;
		z = x;
		x = t;
	}

	if (y > z) {
		t = y;
		y = z;
		z = t;
	}
	printf("从小到大排序：%d %d %d\n", x, y, z);
	return 0;
}
