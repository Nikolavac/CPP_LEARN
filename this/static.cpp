//静态成员static
#include<iostream>
using namespace std;

//--------------------------------------------------//
//静态成员变量被所有对象共享
//sizeof 不计算静态成员变量大小
//静态成员函数不做用于某个对象上面
//不需要通过对象来就能访问
//静态成员变量 本质上是全局变量，对象不存在时，类的静态成员变量也存在
//将与类有关的全局变量和全局函数封装在类内，便于维护

class CRectangle
{
    private:
        int w,h;
        static int nTotalArea;//静态成员变量
        static int nTotalNumber;
    public:
        static int publicValue;
        CRectangle(int w_,int h_);
        CRectangle(CRectangle &r);
        ~CRectangle();
        static int GetValue(){ return nTotalArea; }
        //静态成员函数不能访问非静态变量，也不能调用非静态成员函数，因为不知道调用哪个对象的
        static void PrintTotal();//静态成员函数
        //
        void PrintTotal_NoneStatic();

};

int CRectangle::nTotalArea = 0; //类的静态成员变量需要在类外分配内存空间
int CRectangle::nTotalNumber = 0;
//构造函数
CRectangle::CRectangle(int w_,int h_)
{
    w = w_;
    h = h_;
    nTotalArea += w*h;
    nTotalNumber++;
    cout << "construct called"<<endl;
}
//拷贝构造函数
CRectangle::CRectangle(CRectangle &r)
{
    w =r.w;
    h =r.h;
    nTotalNumber++;
    nTotalArea += w*h;
    cout << "Copy Called"<<endl;
}
//析构函数
CRectangle::~CRectangle()
{
    nTotalNumber--;
    nTotalArea -= w*h;

}

void CRectangle::PrintTotal()
{
    cout << nTotalArea << " " << nTotalNumber <<endl;
}

//--------------------------------------------------//
int main(int argc, char const *argv[])
{/*
    //访问静态成员
    CRectangle::PrintTotal();
    //访问静态成员,类的私有成员不能直接访问
    cout<<CRectangle::publicValue<<endl;
    //访问静态成员
    CRectangle r(1,2);
    r.PrintTotal();
    CRectangle *p = &r;
    //指针访问
    p->PrintTotal();
    //引用访问
    CRectangle &ref = r;
    int n = ref.publicValue;

    system("pause");
    return 0;
*/
    //存在问题，不是所有对象都通过构造函数生成，也可能通过拷贝构造函数生成
    //拷贝构造函数的调用：
    //<1> 以类作为函数参数，或返回值
    //拷贝构造函数不计数，析构函数减掉总数，故出错
    CRectangle r1(2,3),r(2,2);
    CRectangle r3=r1;

    CRectangle::PrintTotal();
    r1.PrintTotal();
    system("pause");
    return 0;
}
