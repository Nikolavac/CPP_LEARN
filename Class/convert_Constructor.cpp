#include <iostream>
using namespace std;


//类型转换构造函数,不是拷贝构造函数
//用于实现类型的自动转换
//有编译器自动调用生成一个无名的临时对象

class Complex
{
    public:
        double real,imag;
        //类型转换构造函数
        Complex(int i){
            cout<<"IntConstructor"<<endl;
            real = i;
            imag = 0;
        };
        Complex(double r,double i){
            real = r;
            imag = i;
        }
};

int main(int argc, char const *argv[])
{
    Complex c1(7,8);
    Complex c2 = 12;
    c1 =9;//将9转换成一个临时的对象，并将9这个对象赋值给c1
    cout << c1.real<<","<<c1.imag<<endl;
    system("pause"); 
    return 0;
}
