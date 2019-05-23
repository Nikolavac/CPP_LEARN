#include<iostream>
using namespace std;

//this 指针指向成员函数所作用的对象
// 静态成员函数不能使用this指针，因为静态成员函数不具体作用于某个特定对象
class Complex
{
    public:
        double real,imag;
        void print(){cout<<real<<","<<imag;}
        //构造函数，初始化列表方式
        Complex(double r, double i):real(r),imag(i)
        {   }
        //返回Complex类型对象，this 指针指向AddOne所作用的对象
        Complex AddOne()
        {
            this->real++;//等价于 real++
            this->print();//等价于print
            return *this;//返回这个对象自身
        }

};
int main(int argc, char const *argv[])
{
    Complex c1(1,1),c2(0,0);
    c2 = c1.AddOne();//this 指针指向C1
    system("pause");
    return 0;
}
