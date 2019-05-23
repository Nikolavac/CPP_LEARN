//函数对象，重载（）
#include<iostream>
using namespace std;

class CMyAverage
{
    public: 
    double operator() (int a1, int a2,int a3)
    {
        return (a1+a2+a3)/3;
    }
};

int main(int argc, char const *argv[])
{
    CMyAverage average;
    cout << average(1,2,3);//average.operator() (1,2,3)   
    system("pause");
    return 0;
}
