/*
 * 这段代码主要帮助自己加深对面向对象的理解，剥开其神秘面纱
 * 代码的关键就是用指针把函数和结构体进行关联
 */
#include <stdio.h>

// 定义一个结构体，包含 A、B 两个字段，可以把其理解为类属性；
// 还包含了两个函数指针，接收 struct Alias 类型指针为参数，
// 其实就是指向自身的指针，这个指针参数很关键，在函数内部使用时可以将其理解为 $this，
typedef struct Alias{
	char A;
	char B;
	void (*pA)(struct Alias *alias);
	void (*pB)(struct Alias *alias);
} Class;

// 这个就是“类方法”的具体实现了
void printA(Class *class) {
	printf("Class.A: %c\n", class->A);
}

// 这个就是“类方法”的具体实现了
void printB(Class *class) {
	printf("Class.B: %c\n", class->B);
}

int main() {
	// 这类似于创建一个对象，并初始化属性和方法
	Class class = {
		A: 'A',
		B: 'B',
		pA: printA,
		pB: printB,
	};

	// 调用“类方法”
	class.pA(&class);
	class.pB(&class);
}
