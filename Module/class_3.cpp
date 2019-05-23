#include<iostream>
using namespace std;

//类模板从类模板派生
template<class T1,class T2>
class A
{
    T1 v1;
    T2 v2;
};


template<class T1,class T2>
class B : public A<T2,T1>
{
    T1 v3;
    T2 v4;

};


template<class T>
class C : public B<T,T>
{
    T v5;
};


//类模板从模板类派生
template<class T1,class T2>
class D:public A<double,int>
{
    T1 v5;
    T2 v10;
};
int main(int argc, char const *argv[])
{   
    //注意，这里B的类型参数表T1,T2与A的相同，故A<T2,T1>表明了实际的类型参数
    B<int,double> obj1;
    C<int> obj2;
    D<char,char> ohbkl;

    
    system("pause");
    return 0;
}
