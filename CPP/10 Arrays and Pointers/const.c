#include <stdio.h>
#define MONTHS 12

int main()
{
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    double locked[4] = {0.08, 0.075, 0.0725, 0.07};
    const double *pd = rates;  // pd 指向数组的首元素，这表明不能使用 pd 来更改它所指向的值
    double *pn = locked;

    printf("pd = %p, *pd = %.2lf\n", pd, *pd);

//    days[9] = 44;  // 编译错误

//    *pd = 39.89;  // 不允许

//    pd[2] = 222.22;  // 不允许

//    rates[0] = 99.99;  // 允许，因为 rates 未被 const 限定
//    printf("*pd = %.2lf\n", *pd);

//    pd ++;  // 让 pd 指向 rates[1] -- 没问题
//    printf("pd ++ = %p\n", pd);

//    pd = locked;  // 有效
//    printf("pd = %p\n", pd);

    pd = &rates[3];  // 有效
    printf("pd = %p\n", pd);

//    pn = days;  // 无效，这个规则非常合理。否则，通过指针就能改变 const 数组中的数据。

    return 0;
}