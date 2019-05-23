#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
    int *pn;
    //创建int型的变量空间
    pn = new int;
    *pn =5;
    cout <<*pn<<endl;
    int *px;
    // P = new T[N] N可以是表达式 T为类型
    int i =5;
    px = new int[i*20];
    pn[0] = 20;
    //数组越界
    pn[100] = 30;
    //new 的返回值都是 T*返回指针类型  int *p = new int 

    //delete 释放动态分配空间
    int *p = new int ;
    *p = 5;
    //delete p 不能连续delete一片空间多次
    delete p;
    //释放连续空间
    int *p = new int[20];
    p[0] = 1;
    //释放数组时，delete 要带[]，不带[]中括号，不能完全释放动态空间
    delete []p;

    
    system("pause");
    return 0;
}
