#include<iostream>
#include<algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
    int x = 100,y=200,z=300;
    //lambda表达式，（1.2，2.5）是参数
    cout << [](double a,double b){return a+b;}(1.2,2.5) << endl;
    //Lambda的函数体后面要有；
    //[]内为外部变量的值的调用方式，（int n）是函数的变量
    //auto为自动适应类型
    auto ff = [=,&y,&z](int n)
    {
        cout << x << endl;
        y++;
        z++;
        return n*n;
    };
    cout << ff(15) << endl;
    cout << y << "," <<z << endl;

    int a[4] = {4,2,11,33};
    //x,y为参与比较的两个变量，比较个位数大小
    sort(a,a+4,[](int x,int y)->bool{return x%10 < y%10;});
    //遍历a
    for_each(a,a+4,[](int x){cout << x << " ";});
    system("pause");
    return 0;
}
