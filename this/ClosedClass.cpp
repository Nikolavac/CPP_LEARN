//成员对象和封闭类enclosing 
#include<iostream>
using namespace std;
//有成员对象的类称为封闭类
//类的成员为其他类的对象
class CTyre
{
    private:
        int radius;
        int width;
    public:
    CTyre(int r, int w):radius(r),width(w){cout<<"CTyre Constructor"<<endl;}
    ~CTyre(){cout<<"CTyre Destructor"<<endl;}
};

class CEngine
{
    public:
        CEngine(){cout << "Engine Constructor"<<endl;}
        ~CEngine(){cout << "Engine Destructor"<<endl;}

};

//CCar是一个封闭类
class CCar
{
    private:
        int price;
        //先初始化tyre再初始化Engine
        //先调用先声明的成员对象的构造函数
        CTyre tyre;//成员对象
        CEngine Engine;
        
    public:
        //若不写构造函数，则使用无参构造函数，则Tyre则无法初始化，Engine则没有问题
        CCar(int price, int tr, int tw);
        ~CCar(){cout<<"Ccar Destructor"<<endl;}
};


class A
{
    public:
        A(){cout<<"Defualt"<<endl;}
        A(A &a){cout << "Copy" <<endl;}
};

class B
{
    A a;
};


//构造函数
//tyre初始化列表内可以是任意表达式
//封闭类构造函数和析构函数的调用顺序
//<1>封闭类生成对象的时候，先执行所有成员对象的构造函数，才执行封闭类的构造函数
//      防止需要使用成员对象继续初始化时，成员对象还没有被初始化
//<2>对象成员的构造函数的初始化顺序与对象成员在类内的声明顺序相关，与成员初始化列表中的顺序无关
//<3>先执行封闭类的析构函数，再执行成员对象的析构函数(先构造的后析构)
CCar::CCar(int p,int tr,int tw):price(p),tyre(tr,tw){cout<<"Ccar Constructor"<<endl;};

int main(int argc, char const *argv[])
{
    //CCar(1000,20,265);
    //b1 为无参构造函数初始化 故调用A的默认无参构造函数-> Default
    //b2 为拷贝构造函数初始化 B的默认拷贝构造函数会初始化b2.a则会调用A的拷贝构造函数来用b1.a初始化b2.a
    B b1,b2(b1);
    system("pause");
    return 0;
}
