#include "iostream"
using namespace std;
// 内联函数
inline int Max(int a, int b)
{
    if (a>b) return a;
    return b;
}
//重载 overload
//编译器根据参数个数和类型决定调用函数
int max(double f1, double f2);
int max(int n1, int n2);
int max(int n1, int n2, int n3);
 
// 函数的参数可以缺省值,提高函数的可扩充性
void func(int x1,int x2=2,int x3= 3);


int main(int argc, char const *argv[])
{
    //多次执行，且执行较快，减少函数开销。 
    //内联函数通过编译器将函数代码直接插入调用有语句的地方
    // 关键字 inline 

    return 0;
}
