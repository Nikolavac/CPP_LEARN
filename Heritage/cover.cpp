#include<iostream>
using namespace std;
//覆盖
//派生类的成员与基类同名
//通常成员变量不同名
//c的存储空间： int i ,int i 两个变量
class d
{
    public:
        int i;
};
class c : public d
{
    public:
        int i;
};
//类的保护成员
//基类的私有成员： 基类的成员函数和友元函数
//基类的公有成员： 基类的成员函数、友元函数、派生类的成员函数、派生类的友元函数、其他函数
//基类的保护成员： 基类的成员函数、基类的友元函数、派生类的成员函数只能访问当前对象的保护成员

class Father
{
    private:
        int nPrivate;
    public:
        int nPublic;
    protected:
        int nProtected;
};
class Son : public Father
{   
    public:
    void Access()
    {
        //nPrivate = 1;    不能访问私有成员
        nPublic = 1;
        nProtected  = 1;    //访问当前对象的基类的保护成员
        Son f;
        f.nProtected =1;  // 非当前对象的基类的保护成员，出错
        cout << f.nProtected <<endl;
    }
};

int main(int argc, char const *argv[])
{   
    c d;
    d.i = 1;
    //访问基类的成员变量
    d.d::i =2;
    Son s;
    s.Access();

    Father f;
    Son s1 ;
    f.nPublic = 1;
    s.nPublic = 1;
    //f.nProtected 只能在基类或派生类内部被访问，也可以通过友元函数访问
    //s.nProtected 只能在基类或派生类内部被访问，也可以通过友元函数访问
    system("pause");
    return 0;
}
