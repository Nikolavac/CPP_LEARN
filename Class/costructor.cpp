//构造函数，名字与类名相同，不含返回值
//对对象进行初始化
//编译器默认生成无参数的构造函数
//对象生成时，自动调用构造函数
//一个类有多个构造函数
#include <iostream>
using namespace std;

//---------------------------------------------------------------//
class Complex
{
    private:
        double real,imag;
    public:
        void set(double r, double i);
        //构造函数的重载
        //Complex(double r, double i=0); //缺省参数
        Complex(double r, double i);
        Complex(double r);
        Complex(Complex c1, Complex c2);
        void printComplex();
};

Complex::Complex(double r,double i)
{
    real = r;
    imag = i;
}

Complex::Complex(Complex c1, Complex c2)
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}

//---------------------------------------------------------------//
class Sample
{
    private:
        int x;
    public:
        Sample();
        Sample(int a);
};

Sample::Sample()
{
    cout << "Constrctor_1"<<endl;
}

Sample::Sample(int a)
{
    x=a;
    cout << "Constructor_2"<<endl;
}

//---------------------------------------------------------------//
class Test
{
    public:
        Test(int n);
        Test(int m, int n);
        Test();
};



//---------------------------------------------------------------//
int main(int argc, char const *argv[])
{   
    Complex c1(1,1); // 有构造函数时默认构造函数不执行，构造函数需要初始化参数
    //Complex c1; 报错
    Complex *pc = new Complex(2,3); // 默认构造函数
    //构造函数在对象数组中的应用
    Sample array1[2];
    cout<<"Step_1"<<endl;
    Sample array2[2] = {4,5}; //表示两个对象的初始化参数分别为4，5
    cout<<"Step_2"<<endl;
    Sample array3[2] = {3};
    cout<<"Step_3"<<endl;
    Sample* array4 = new Sample[2];
    delete [] array4;
    //多参数的构造函数数组,分别123构造函数调用
    Test array5[3] = {1,Test(3,4)};
    //指针数组
    Test* Parray2[3]; // 并不会初始化创建对象
    //只会初始化两个对象，数组中的第三个指针并没有指向任何一个对象
    Test* Parray[3] = {new Test(4), new Test(2,3)};
    system("pause");
    return 0;
}

