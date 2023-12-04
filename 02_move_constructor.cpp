#include <iostream>
#include <utility>

/*
拷贝构造函数和移动构造函数的区别：
1,目的不同：
移动构造函数的主要目的是通过“移动”资源的所有权，而不是创建资源的副本。这用于提高性能，特别是在涉及动态分配的资源时。
拷贝构造函数则用于创建一个新对象，该对象是原始对象的精确副本。
2,性能：
移动构造函数通常比拷贝构造函数更高效，因为它不涉及资源的实际复制，而只是转移资源的所有权。
拷贝构造函数会创建原始对象的一个新副本，这可能涉及深度复制，对于大型数据结构可能会很耗时。
3,参数：
移动构造函数接受右值引用（&&）作为参数，允许“窃取”右值的资源。
拷贝构造函数接受常量引用（const &）作为参数，因为它需要原始对象的一个副本。
4，作用:
移动拷贝的作用:数组扩容
*/

class MyString{
private:
    char* _data; 

public:
    MyString(const char* s = ""): _data(nullptr) {
        if(s) {
            std::size_t n = std::strlen(s) + 1;
            _data = new char[n];
            std::memcpy(_data, s, n);
        }
        std::cout << "create" << std::endl;
    }

    ~MyString() {
        std::cout << "delete" << std::endl;
        delete[] _data;
    }
    //拷贝构造函数
    MyString(const MyString& other):MyString(other._data) {
        std::cout << "copy constructor" << std::endl;
    }
    //移动构造函数
    MyString(MyString&& other) {
        std::cout << "move constructor" << std::endl;
        this->_data = other._data;
        other._data = nullptr;
    }
    void changContent(const char *sr = "") {
        if(sr) {
            std::size_t n = std::strlen(sr) + 1;
            this->_data = new char[n];
            std::memcpy(this->_data, sr, n);
        }
    }
    void MyPrint() {
        std::cout << this->_data << std::endl;
    }
};

int main() {
    //拷贝构造测试
    MyString str("hello world!");
    MyString str2(str);
    str2.changContent("welcome you");
    str.MyPrint();
    str2.MyPrint();
    //移动构造测试
    MyString str3(std::move(str));
    str3.changContent("welcome you");
    str3.MyPrint();
    // str.MyPrint();  //打开运行错误，移动构造之后str的_data指针已经是空指针了，无法对空指针进行操作。

    return 0;
}