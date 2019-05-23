#include<iostream>
using namespace std;
//虚析构函数
//通过基类的指针删除派生类对象时，通常只调用基类的析构函数
//析构派生类的对象的时候，应该先调用派生类的析构函数，再调用基类的析构函数

//将基类的析构函数定义为virtual函数，此时则调用派生类的析构函数，再是基类的析构函数
//同时，一般来说如果定义了虚函数，析构函数一般定义为析构函数
//若定义一个类为基类使用，则也应该将析构函数定义为析构函数
//构造函数不能是析构函数 

class son 
{
    public:
        virtual ~son(){cout << "son" <<endl;};  
};

class grandson:public son
{
    public:
    // 可以省略virtual，同名虚函数
        ~grandson(){cout <<"grandson"<<endl;};
};

//解决通过基类指针delete对象时，不能调用派生类的析构函数的问题
int main(int argc, char const *argv[])
{
    son* s;
    s = new grandson();
    delete s;
    system("pause");
    return 0;
}
