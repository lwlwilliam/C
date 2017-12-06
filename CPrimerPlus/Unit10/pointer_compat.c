/* 指针兼容性 */
/* 以下无效的赋值表达式语句中涉及的两个指针都是指向不同的类型。 */
#include <stdio.h>
int main()
{
    int n = 5;
    double x;
    int *p1 = &n;
    double *pd = &x;

    x = n;  // 隐式类型转换
//    pd = p1;  // 编译时错误


    // 更复杂的类型
    int *pt;
    int (*pa)[3];
    int ar1[2][3];
    int ar2[3][2];
    int **p2;  // 一个指向指针的指针

    pt = &ar1[0][0];  // 都是指向 int 的指针
    pt = ar1[0];      // 都是指向 int 的指针
//    pt = ar1;         // 无效
    pa = ar1;         // 都是指向内含 3 个 int 类型元素数组的指针
//    pa = ar2;         // 无效
    p2 = &pt;         // both pointer-to-int *
    *p2 = ar2[0];     // 都是指向 int 的指针
//    p2 = ar2;         // 无效



    // 多重解引用让人费解
    int j = 20;
    const int k = 23;
    int *pj = &j;
    const int *pk = &k;
    const int **ppk;
//    pj = pk;     // 不安全 -- 把 const 指针赋给非 const 指针
    pk = pj;     // 有效 -- 把非 const 指针赋给 const指针
//    ppk = &pj;   // 不安全 -- 嵌套指针类型赋值

    return 0;
}