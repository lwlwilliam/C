/*
 * 这段代码主要帮助自己加深对面向对象的理解，剥开其神秘面纱
 * 代码的关键就是用指针把函数和结构体进行关联
 */
#include <stdio.h>
#include "./class.h"

int main() {
	// 这类似于创建一个对象，并初始化属性和方法
	Class class = {
		A: 'A',
		B: 'B',
		printA: printA,
		printB: printB,
	};

	// 调用“类方法”
	class.printA(&class);
	class.printB(&class);
}

// 这个就是“类方法”的具体实现了
void printA(Class *class) {
	printf("Class->A = %c\n", class->A);
}

// 这个就是“类方法”的具体实现了
void printB(Class *class) {
	printf("Class->B = %c\n", class->B);
}
