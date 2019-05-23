#include<iostream>
using namespace std;


template<class T>
class A
{
    public:
        //类模板里面的模板参数
        template<class T2>
        void Func(T2 t){cout << t}
};

template<class T ,int size>
class CArray
{
    private:
        T array[size];
    public:
        void Print()
        {
            for(int i = 0 ; i< size ;i++)
            {
                cout << array[i] << " ";
            }
        }
};
int main(int argc, char const *argv[])
{
    A<int> a;
    a.Func('k');
    a.Func("Hello");

    CArray<int,40> a1;
    CArray<double,50> a2;

    system("pause");
    return 0;
}
