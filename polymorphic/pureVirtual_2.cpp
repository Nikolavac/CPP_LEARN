#include<iostream>
using namespace std;

//纯虚函数和抽象类
//抽象类：如果一个类包含纯虚函数，抽象类只能作为基类使用，不能创建对象
//可以定义抽象类的指针和引用 A*pa = new A; 不行，因为A不能创建对象
//抽象类的成员函数内可以调用纯虚函数，但是在构造函数和析构函数内部不能调用纯虚函数
//成员函数内部调用纯虚函数属于多态
//当一个类从抽象类中派生而来，那么当且仅当它实现了基类中的所有纯虚函数，才称为非抽象类


class A
{//A是一个抽象类，不能有对象
    private:
        int a;
    public:
        //纯虚函数
        virtual void f() = 0;
        //此时this一定是指向派生类的对象，因为抽象类不能有对象
        //所以基类的成员函数可以调用基类中的纯虚函数，因为在实际调用中
        //this指针指向的只可能是派生类的对象
        //是多态，此时调用b的f()
        void g() {this->f();}
        //构造函数中调用虚函数不是多态，不可调用纯虚函数
        A(){/*f()*/}
};

class B:public A
{
    public:
    //实现基类的纯虚函数
        void f(){cout << "B" << endl;}
};
int main(int argc, char const *argv[])
{
    B b;
    //从A中继承g()
    b.g(); 
    system("pause");
    return 0;
}
