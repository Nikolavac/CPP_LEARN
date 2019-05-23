#include<iostream>
using namespace std;

//函数模板和类模板
//Template<class,class>
//void Swap(T& x,T& y)

//将T替换成实际的类型
template <class T>
void Swap(T& x,T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
template <class T1,class T2>
void print(T1 arg1,T2 arg2)
{
    cout << arg1 << arg2 << endl;
    return arg2;
}
template<class T>
T max(T a[],int size)
{
    T tempMax = a[0];
    for(int i=0;i<size;i++)
    {
        if( tempMax < a[i] )
        {
            tempMax = a[i];
        }
    }
    return tempMax;
}

template<class T>
T inc(T n)
{
    return 1+n;
}

//函数模板的重载,形参表或类型参数表不同即可
template<class T1>
void print(T1 arg1, T1 arg2);

template<class T1,class T2>
void print(T1 arg1);

template<class T1>
void print(T1 arg1);


//模板及函数调用顺序
//1>先找普通函数
//2>在参数匹配的模板函数
//3>实参自动类型转换后能匹配的普通函数
//函数模板不会进行自动类型转换后在进行模板的类型匹配


//Map模板
template<class T,class Pred>
//s e x 指针，op是函数指针
void Map(T s,T e,T x,Pred op)
{
    for(;s!= e;++s,++x)
    {
        *x = op(*s);
    }
}
int Cube(int x){return x*x*x;}
double Square(double x){return x*x;}


int a[5] = {1,2,3,4,5},b[5];
double d[5] = {1.1,1.2,1.3,1.4,1.5},c[5];


int main(int argc, char const *argv[])
{
    int n = 1,m=2;
    Swap(n,m);
    double f = 1.2 ,g = 3.4;
    Swap(f,g);
    //模板的实例化，指明类型double，若不指明则为int
    cout << inc<double>(4)/2;
    //void Map(int* a,int* s,int* x,double* (op)(double))
    Map(a,a+5,b,Square);
    for(int i=0;i<5;i++)
    {
        cout << b[i] << endl;
    }

    Map(a,a+5,b,Cube);
    for(int i=0;i<5;i++)
    {
        cout << b[i] << endl;
    }


    Map(d,d+5,c,Square);
    for(int i=0;i<5;i++)
    {
        cout << c[i] << endl;
    }
    system("pause");
    return 0;
}
