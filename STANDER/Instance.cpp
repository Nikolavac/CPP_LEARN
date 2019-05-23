#include<iostream>
//流操作算子
#include<iomanip>
using namespace std;
//浮点数精度
//设置宽度
//输出不同进制

int main(int argc, char const *argv[])
{
    //--------------------------------------------------------//
    //不同进制输出,连续有效
    int n = 10;
    cout << n << endl;
    cout << hex << n << endl;
    cout << dec << n << '\n'
    << oct << n << endl;
    cout << dec << endl;
    //--------------------------------------------------------//
    //浮点数输出精度
    //precision setprecision
    //precision是osteam类成员函数cout.precision
    //setprecision连续起作用，设置一次以后一直有效
    //setprecision cout << setprecision(5);
    double x = 1234567.89,y=12.34567;
    //整数不受setprecision影响
    n = 1234567;
    int m = 13;
    cout << setprecision(6) << x <<endl
    <<y <<endl << n << endl << m << endl; 
    //设置定点位数
    x = 1234567.89;
    cout << setiosflags(ios::fixed) << setprecision(5) << x <<endl;
    //取消setprecision(5) 
    cout << setiosflags(ios::fixed) << setprecision(5) << x <<endl
         << resetiosflags(ios::fixed) << x << endl;
    system("pause");
    return 0;
}
