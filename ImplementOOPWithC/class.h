// 定义一个结构体，包含 A、B 两个字段，可以把其理解为类属性；
// 还包含了两个函数指针，接收 struct Alias 类型指针为参数，
// 其实就是指向自身的指针，这个指针参数很关键，在函数内部使用时可以将其理解为 $this，
typedef struct Alias{
	char A;
	char B;
	void (*printA)(struct Alias *alias);
	void (*printB)(struct Alias *alias);
} Class;

void printA(Class *class);
void printB(Class *class);
