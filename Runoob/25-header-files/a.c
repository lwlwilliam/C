#include <stdio.h>
#include "a.h"

int main()
{
	test();
}

void test(void)
{
	printf("%s : %d\n", __FILE__, __LINE__);
}
