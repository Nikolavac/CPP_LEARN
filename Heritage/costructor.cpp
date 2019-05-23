#include<iostream>
using namespace std;
//派生类的初始化，以及构造函数
//先执行基类的构造函数
//调用基类的构造函数的方式有两种：
//显式的调用，派生类的构造函数的初始化列表
//隐式调用基类的无参构造函数
//Public 继承的赋值兼容规则
//派生类对象可以赋值给基类对象
//派生类可以初始化基类的引用
//派生类的对象的地址可以赋值给基类的指针
//base b;
//drive d;
//b=d; 可以
//base& v = d; 可以
//base* pb = &d; 可以
//要求派生为public


//直接基类与间接基类
//构造函数只需指明直接基类的初始化方式
class Bug
{
    private:
        int nLegs;
        int nColors;
    public:
        int nType;
        Bug(int legs,int color);
        void PrintBug(){};

};

Bug :: Bug (int legs,int color):nLegs(legs),nColors(color)
{
    nType = 1;
}

class FlyBug : public Bug
{
    private:
        int nWings;
    public:
        FlyBug(int nLegs_,int nColors_,int nWings_);
};

FlyBug:: FlyBug(int nLegs_,int nColors_,int nWings_):Bug(nLegs_,nColors_),nWings(nWings_)
{
    nType = 2;
}
int main(int argc, char const *argv[])
{   
    FlyBug f(2,3,4);

    system("pause");
    return 0;
}
