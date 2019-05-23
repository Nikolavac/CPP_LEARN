#include "iostream"
#include <cstring>
using namespace std;

// 成员变量和成员函数统称为成员
// Rectangle 是用户自定义类型
// 【对象】占用的内存大小是全部成员变量的大小之和
// 对象有自己的存储空间

class Cemployee
{
    //缺省为私有成员
    private:
        char szName[30];
    public:
        int salary;
        void setName(char* name);
        void getName(char* name);
        void averageSalary(Cemployee e1, Cemployee e2);
    protected:
    //成员函数的重载及参数缺省
        void valuex(int val);
        int valuex();
    //注意避免重载与缺省参数的二义性


};

//注意给出返回值类型
//类外定义成员函数
void Cemployee :: setName(char* name)
{
    strcpy(szName,name);
} 

void Cemployee:: getName(char* name)
{
    strcpy(name,szName);
}

void Cemployee :: averageSalary(Cemployee e1, Cemployee e2)
{
    cout<<e1.szName;
    salary = (e1.salary+e2.salary)/2;

}


int main(int argc, char const *argv[])
{
    Cemployee e;
    //strcpy(e.szName,"time2323"); 类外部不能访问私有变量
    e.setName("Tim22323");
    e.salary = 5000;
    char* name = new char[50];
    e.getName(name);
    cout<<name<<endl;
    system("pause");
    return 0;
}
