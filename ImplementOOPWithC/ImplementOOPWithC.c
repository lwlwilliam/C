/*
 * 这段代码主要帮助自己加深对面向对象的理解，剥开其神秘面纱
 * 代码的关键就是用指针把函数和结构体进行关联
 */
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

	return 0;
}

