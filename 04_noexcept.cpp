#include <iostream>

/*
noexcept 是 C++11 引入的关键字，用于指示一个函数在执行期间是否会抛出异常。它的作用是告诉编译器，某个函数或表达式不会引发异常，
以便编译器可以进行一些性能优化。

用法1：
void myFunction() noexcept;
这种用法表示 myFunction 在执行期间不会抛出异常。如果 myFunction 在执行期间抛出了异常，程序会调用 std::terminate 来终止。
这对于一些性能关键的代码路径很有用，因为它允许编译器进行更好的优化，而无需生成处理异常的额外代码。

用法2：
int result = foo() noexcept;
这种用法表示 foo() 表达式不会在执行期间抛出异常。如果 foo() 在执行期间抛出异常，程序会调用 std::unexpected 来处理异常。

*/

// 函数声明，指定不会抛出异常
void myFunction() noexcept;

// 函数定义，实现不会抛出异常
void myFunction() noexcept {
    std::cout << "Executing myFunction without throwing exceptions." << std::endl;
}

// 另一个函数，可能抛出异常
void potentiallyThrowsException() {
    throw std::runtime_error("This function throws an exception.");
}

int main() {
    try {
        // 调用不会抛出异常的函数
        myFunction();

        // 调用可能抛出异常的函数
        potentiallyThrowsException();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
