### 模块化程序设计

在程序中，定义函数位置在main函数后时，这时候，应该在main函数之前或main函数中的开头部分，对函数进行“声明”。函数声明的作用是把有关函数的信息（函数名、函数类型、函数参数的个数与类型）通知编译系统，以便于在编译系统对程序进行编译时，在进行到main函数调用函数时知道它们是函数而不是变量或其他对象。

C语言要求，在程序中用到的所有函数，必须“先定义，后使用”。例如想用max求两个数的最大值。必须先按规范对它进行定义，指定它的名字、函数返回类型、函数实现的功能以及参数的个数和类型，将这些信息通知给编译系统。这样程序执行max函数时，编译系统就会按照定义式所指定的功能去执行。如果事先不定义，编译系统是无从知晓max是什么，要实现什么功能。

对于C编译系统提供的库函数，是由编译系统事先定义好的，库文件中包含了对各函数的定义。程序设计者不必自己定义，只需要用#include指令把有关的头文件包含到本文件中即可。

库函数只提供了最基本、最通用的一些函数，而不可能包括人们在实际应用中所用到的所有函数，我们往往需要自定义一些想用而库函数并没有提供的函数。


> 函数调用过程

1. 在定义函数中指定的形参，在未出现函数调用时，他们并不占内存中的存储单元。在发生函数调用时，函数max的形参被临时分配内存单元；

2. 将实参对应的值传递给形参；

3. 在执行max函数期间，由于形参已经有值，就可以利用形参进行有关运算了；

4. 通过return语句将运算得到的值带回主调函数。应当注意返回值的类型和函数类型一致；

5. 调用结束，形参单元被释放。注意：实参单元仍保持原值和存储单元，自始至终未发生变化。形参会临时占用内存存储单元，但是实参和形参在内存中占用的存储单元是不同的；

> 函数的递归调用

递归调用：在调用一个函数的过程中又出现直接或间接的调用该函数本身，称为函数的递归调用：

```
int fun(int a)
{
	int b, c;
	c = fun(b);
	return (2*c);
}
```

> 数组与函数

数组元素可以作用函数实参，不能作为函数形参。因为形参是在函数被调用时临时分配的存储单元，不可能作为一个数组元素单独分配存储单元（数组是一个整体，在内存中占边续的一段存储单元）。在用数组元素作为函数实参时，把实参的值传给形参，是“值传递”的方式。

> 数组名作为函数参数

除了可以用数组元素作为函数的参数外，还可以用数组名做函数参数（包括实参和形参）。注意：用数组元素作为实参时，向形参变量传递的是数组所对应数组元素的值，而用数组名做函数实参时，向形参（数组名或指针变量）传递的是数组首元素的地址。

