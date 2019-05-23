#include<iostream>
using namespace std;
//预算符的重载
//只能基本类型的加减乘除等
//运算符重载允许不同类型的变量加减乘除
//实质还是函数重载，可以把运算符重载为普通函数，也可重载为成员函数
//返回值类型  Operator  运算符 （形参表）{}
//【Operator +】

class CComplex
{
    public:
        double real,imag;
        CComplex(double r,double i):real(r),imag(i){}
        //构造函数的重载
        CComplex(){}
        //减号的重载
        CComplex operator-(const CComplex &c);
};

//重载为普通函数，参数个数为原运算符参数个数
CComplex operator+(const CComplex &a, const CComplex &b)
{
    //构造函数
    return  CComplex(a.real + b.real,a.imag + b.imag);//返回无名临时对象
}

//重载为成员函数，参数个数为原运算符参数个数-1
CComplex CComplex::operator-(const CComplex &c)
{
    return CComplex(real - c.real,imag - c.imag);//返回无名临时对象
}

int main(int argc, char const *argv[])
{
    CComplex a(4,4),b(3,3);
    CComplex c;
    c=a+b;//operator+(a,b)
    cout << c.real <<","<<c.imag<<endl;
    cout <<(a-b).real<<endl;//a.operator-(b)
    system("pause");
    return 0;
}
