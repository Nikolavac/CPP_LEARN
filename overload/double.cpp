//类型转换运算符
#include<iostream>
using namespace std;

class CComplex 
{
    double real,imag;
    public:
        CComplex(double r,double i):real(r),imag(i){};
        //重载类型转换double,不需要写返回值类型，其实是double类型
        operator double() {return real;}

};
int main(int argc, char const *argv[])
{   
    CComplex c1(2,3);
    cout<< (double)c1 <<endl;
    //double n = 2 + c.operator double()
    double n = 2+c1;
    cout << n;
    system("pause");
    return 0;
}
