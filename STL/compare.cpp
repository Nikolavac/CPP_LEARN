//binary_search 折半查找 要求操作的容器内部为排序后的
//sort 进行排序
#include<iostream>
#include<algorithm>
using namespace std;

class A
{
    int v;
    public:
        A(int n):v(n){}
        //const 修饰的成员函数内，不能修改任何成员变量
        //const 修饰的成员函数也不能调用非const类型的成员函数
        bool operator <(const A& s) const
        {   
            //任意两个class A的对象都不会小于彼此
            cout << v << "<" << s.v << "?" << endl;
            return false;
        }
        bool operator == (const A& s2) const
        {
            cout << v << "==" << s2.v << "?" << endl;
            return v == s2.v;
        }
};  


int main(int argc, char const *argv[])
{
    A a[] = {A(1),A(2),A(3),A(4),A(5)};
    // == 并没有被调用，并不判断是否==
    //判断 1<9 -> False  9<1 -> False 则 9 == 1
    cout << binary_search(a,a+4,A(9));//查找
    system("pause");
    return 0;
}
