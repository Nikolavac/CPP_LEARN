//自增自减运算符重载
//有前置和后置之分
//前置++当作1元运算函数重载
//后遭++当作2元运算符重载，多写一个无用的参数
//T & operator++();//前置++
//T & operator++(,int);后置++
//通常对两种形式的++都进行重载
// ++a 返回a的引用  ++a = 1;可以
// a++ 返回一个临时变量 a a++ = 1不可以
#include<iostream>
using namespace std;

class CDemo
{
    public:
        int Value;
        CDemo(int v):Value(v){}
        CDemo(const CDemo& c)
        {
            Value = c.Value;
        }
        //后置重载
        CDemo operator++(int)
        {   
            CDemo temp(*this);
            Value++;
            return temp;

        }
        //前置重载
        CDemo& operator++()
        {
            ++ Value;
            return *this;
        }
        //后置重载
        CDemo operator--(int)
        {
            CDemo temp(*this);
            Value--;
            return temp;
        }
        //前置重载
        CDemo& operator--()
        {   
            Value--;
            return *this;
        }

        //重载int
        operator int()
        {
            return Value;
        }
};

int main(int argc, char const *argv[])
{   
    CDemo d(5);
    //++i 可能更快
    cout << (d++) <<",";
    //对<<进行重载或者重载强制转换int
    cout << d << ",";
    cout << ++d <<",";
    cout << d << endl;
    cout << d-- <<",";
    cout << d << ",";
    cout << --d <<",";
    cout << d << endl;

    system("pause");
    return 0;
}
//运算符重载注意：
// C++不允许定义新的运算符
// 重载后的运算符应符合习惯
// 重载后的运算符优先级不改变
// 以下不能重载： .  .*  ::  ?:  sizeof 
// [] () -> = 必须声明为成员函数