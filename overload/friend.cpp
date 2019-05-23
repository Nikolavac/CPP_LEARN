#include<iostream>
#include<cstring>
using namespace std;

class CComplex
{
    private:
        double real,imag;
    public:
        CComplex(){};
        CComplex(double r, double i):real(r),imag(i){};
        ~CComplex(){}
        CComplex(const CComplex& a)
        {
            cout<<"Copy Called"<<endl;
            real = a.real;
            imag = a.imag;
        }
        //运算符重载,重载成成员函数
        CComplex operator+(double r);
        //将重载的普通函数定义为友元函数，可以访问私有成员变量
        friend CComplex operator+(double r,const CComplex& c);
};


CComplex CComplex::operator+(double r)
{
    return CComplex(real+r,imag);
}

//普通函数重载
CComplex operator+ (double r,const CComplex& c)
{
    return CComplex(c.real+r,c.imag);
}

int main(int argc, char const *argv[])
{   
    CComplex c;
    c = c+5;
    //报错，需要加法重载成普通函数
    c = 5+c;
    system("pause");
    return 0;
}
