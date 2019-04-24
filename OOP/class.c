#include <stdio.h>
#include "class.h"

// 这个就是“类方法”的具体实现了
void printA(Class *this) {
	printf("this->A = %c\n", this->A);
}

// 这个就是“类方法”的具体实现了
void printB(Class *this) {
	printf("this->B = %c\n", this->B);
}
