#include <stdio.h>
#include "class.h"

// 这个就是“类方法”的具体实现了
void printA(Class *class) {
	printf("Class->A = %c\n", class->A);
}

// 这个就是“类方法”的具体实现了
void printB(Class *class) {
	printf("Class->B = %c\n", class->B);
}
