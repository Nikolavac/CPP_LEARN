//拷贝构造函数
//只有一个参数，为同类对象的引用
// X::X(X&) or X::X(const X&)
// 后者可以以常量对象作为参数
// 编译器默认的拷贝构造函数 可以完成复制供能
// 拷贝构造函数有且只有一个
#include <iostream>
using namespace std;

//------------------------------------------------//
class Complex
{
    public:
        double real,imag;
    Complex();
    //函数的参数必须为类的引用
    Complex(const Complex &c);

};
Complex::Complex(){}
Complex::Complex(const Complex &c)
{
    real = c.real*2;
    imag = c.imag;
    cout << "Copy Constructor"<<endl;
}
//------------------------------------------------//
class A
{
    public:
        int v;
        A(int n){ v = n;};
        A(const A & a)
        {   
            v= a.v;
            cout<<"copy constructor called";
        };
};



//------------------------------------------------//
void func(Complex c1)
{
    cout << "Func_Call" <<endl;
}

A copy()
{
    A b(6);
    return b;
}

//------------------------------------------------//
int main(int argc, char const *argv[])
{
    Complex c1; //自动调用默认的无参构造函数
    //拷贝构造函数的调用实例：
    Complex c2(c1); //用默认的拷贝构造函数初始化，c2复制c1
    Complex c3 = c1;//调用拷贝构造函数
    Complex c4;
    c4 = c1;  // 只是赋值语句，并不调用拷贝构造函数
    cout << "#--------------------#"<<endl;
    //函数的参数为一个对象：有拷贝构造函数进行初始化
    func(c2);
    //函数的返回值是一个对象
    cout << "#--------------------#"<<endl;
    A c5(3);
    c5 = A(3);
    c5 = copy();
    cout<<copy().v<<endl;
    system("pause");
    return 0;
}
