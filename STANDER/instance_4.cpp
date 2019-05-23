#include<iomanip>
#include<iostream>
using namespace std;

//用户自定义的流操纵算子
ostream& tab(ostream& output)
{
    return output <<'\t';
}

//iostream 对 << 进行了重载,形参是指针类型
//ostream& operator << (ostream& (*p)(ostream&));
//cout << tab 与我们定义的操纵算子类型一致
//等价于 *this << '\t'
//等价于 cout << '\t'
int main(int argc, char const *argv[])
{
    cout << "aa" << tab << "BB" << endl;
    system("pause");
    return 0;
}
