#include <iostream>

/*
constexpr 函数是可能在编译期运行的函数，当你在常量表达式中调用constexpr函数时或者用一个constexpr变量来获取constexpr函数结果时，它会在编译期运行。
优点：
1，编译期间求值的constexpr的结果通常会被标记为可读，性能是constexpr 函数的第一大好处；
2，编译期间求值的constexpr函数是纯函数，因此constexpr函数是线程安全的。
编译时计算： constexpr 函数在编译时被计算，而不是在运行时。因此，由于不存在运行时的并发执行，
不存在与多线程相关的数据竞争和同步问题。编译器会在编译时求值并将结果嵌入到生成的代码中，而不需要在运行时进行计算。
*/


constexpr auto gcd(int a, int b) {
    while (b != 0)
    {
        auto t = b;
        b = a % b;
        a = t;
    }

    return a;
    
}

int main() {

    constexpr int i = gcd(11, 121); // 不会产生函数调用
    printf("i = %d\n", i);

    int a = 11;
    int b = 121;
    int j = gcd(a, b); //会产生函数调用
    printf("j = %d\n", j);
}