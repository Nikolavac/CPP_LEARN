#include<iostream>
using namespace std;
//在构造函数和析构函数中调用虚函数，不是多态
//编译时即可确定是自己的虚函数，若自己没有虚函数，则调用直接基类中的虚函数
//派生类中的成员函数与基类同名通参数表，不加virtual关键字也算是虚函数

class myclass
{
    public:
        virtual void hello(){cout << "hello" <<endl;}
        virtual void bye(){cout << "bye" <<endl;}
};


class son :public myclass
{
    public:
    //hello也算虚函数虽然没有virtual关键字
        void hello(){cout <<"son"<<endl;}
        //构造函数析构函数，不存在多态
        son(){hello();}
        ~son(){bye();} 
};

class Grandson:public son
{
    public:
    //同理，是虚函数
    void hello(){cout << "Grand" <<endl;}
    void bye() {cout << "Grand bye" <<endl;}
    Grandson(){cout << "construct"<<endl;}
    ~Grandson(){cout << "delet"<<endl;}
};
int main(int argc, char const *argv[])
{
    Grandson s;
    son* ps;
    ps = &s;
    ps ->hello();//多态，调用Grand的hello()
    system("pause");
    return 0;
}
