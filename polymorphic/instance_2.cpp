#include<iostream>
using namespace std;

//在非构造函数、非析构函数中，调用虚函数就是多态，执行多态的原则
//具体调用哪个函数，要看基类的指针指向的对象是谁
class Base
{
    public:
        void fun1(){fun2();}
        //等价于  void fun1(){this->fun2()}
        //this 是基类的指针 fun2()是虚函数，故是多态、
        //故取决于this所指向的对象
        //Main中 this 指向派生类的对象，故输出Derived
        virtual void fun2(){cout<<"Base"<<endl;}
};

class Derived:public Base
{   
    public:
        virtual void fun2(){cout<<"Derived"<<endl;}
};

int main(int argc, char const *argv[])
{
    Derived d;
    Base *pB = &d;
    pB -> fun1();
    system("pause");
    return 0;
}
