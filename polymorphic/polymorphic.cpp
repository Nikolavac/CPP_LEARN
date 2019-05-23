#include<iostream>
using namespace std;
//虚函数和多态

//虚函数
//virtual 关键字加在成员函数前
//只写在类内，当函数在类外部定义时，不需要写virtual关键字
//构造函数和静态成员函数不能时虚函数

//多态
//派生类的指针可以赋值给基类指针
//1>
//通过基类指针调用基类和派生类中的同名虚函数的时候：
//若指针指向基类对象，则调用基类虚函数
//若指针指向派生类对象，则调用派生类虚函数 
//2>

//以上称为多态

//多态的作用：
//

class CBase
{
    public:
        virtual void SomeVirtualFunction(){cout << "Base Virtual Function"<<endl;}
};
class CDrived : public CBase
{
    public:
        virtual void SomeVirtualFunction(){cout << "Derived Virtual Function"<<endl;}
};
class MoreDrived: public CDrived
{
    public:
        virtual void SomeVirtualFunction(){cout << "More Derived Virtual Function"<<endl;}
}; 

int main(int argc, char const *argv[])
{
    MoreDrived OMore;
    CDrived ODerived;
    CBase Obase;

    MoreDrived* pM = &OMore;
    CDrived* pD = &ODerived;
    CBase* pB = &Obase;

    pB->SomeVirtualFunction();
    pB = pD;
    pB->SomeVirtualFunction();
    pB = pM;
    pB->SomeVirtualFunction();

    //这里定义了基类的指针p，由于派生类的对象的地址可以给基类的指针赋值
    CBase* p = &ODerived;
    //这里p具体指向的是哪一个函数，由p的值决定，这里p指向派生类的对象，故执行派生类的函数
    //通过多态可以不受同名覆盖的影响，
    p->SomeVirtualFunction();
    //同理，调用派生类的成员函数
    //引用的初始化一定是引用某个变量，引用初始化后不可改变
    CBase& r = ODerived;
    r.SomeVirtualFunction();
    //这里将调用基类的成员函数
    //
    CBase& s = Obase;
    s.SomeVirtualFunction();
    system("pause");
    return 0;
}
