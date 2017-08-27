### C强制类型转换

强制类型转换是把变量从一种类型转换为另一种数据类型。例如，如果想存储一个long类型的值到一个简单的整型中，需要把long类型强制转换为int类型。可以使用强制类型转换运算符来把值显式地从一种类型转换为另一种类型，如下：

```
(type_name_ expression
```

> 整数提升

整数提升是指把小于int或unsigned int的整数类型转换为int或unsigned int的过程。


> 常用的算术转换

常用的算术转换是隐式地把值强制转换为相同的类型。编译器首先执行整数提升，如果操作数类型不同，则它们会转换为下列层次中出现的最高层次的类型：

long double <-- double <-- float <-- unsigned long long <-- long long <-- unsigned long <-- long <-- unsigned int <-- int


常用的算术转换不适用于赋值运算符、逻辑运算符&&和||。
