#include<iostream>
using namespace std;

//多态的实现方式
//虚函数表，每个对象中都有虚函数表
//表内是虚函数的地址    
//虚函数的代价：虚函数表和虚函数表内查找

class A
{
    public:
        virtual void func(){cout << "A" <<endl;}

};
class B:public A
{
    public:
        virtual void func(){cout << "B" << endl;}
};
int main(int argc, char const *argv[])
{
    A a;
    A *pa = new B();
    pa ->func();//多态
    //64位操作系统指针是8字节
    //p1 指向 a 的头地址，为a的虚函数表
    long long *p1 = (long long* ) &a;
    //p2 指向 b 的头地址，为b的虚函数表
    long long *p2 = (long long* ) pa;
 
    *p2 = *p1;
    //原本是多态，但是我们已经替换了B的虚函数表地址换位了A的虚函数表
    //故输出A
    pa ->func();
    system("pause");
    return 0;
}
