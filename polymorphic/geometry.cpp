#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

class CGeometry
{
    public:
        //纯虚函数，没有函数体
        virtual double SquareArea() = 0;
        virtual void PritInfo() = 0;
};

class CRect : public CGeometry
{   
    public:
        int w,h;
        virtual double SquareArea();
        virtual void PritInfo();
};  

double CRect:: SquareArea()
{
    return w*h;
}

void CRect:: PritInfo()
{
    cout << "CRectangle"<<SquareArea()<<endl;
}

class CCircle : public CGeometry
{
    public:
        int r;
        virtual double SquareArea();
        virtual void PritInfo();
};  


double CCircle:: SquareArea()
{
    return r*r*3.14;
}

void CCircle:: PritInfo()
{
    cout << "CCircle"<<SquareArea()<<endl;
}


class CTriAngle : public CGeometry
{
    public:
        int a,b,c;
        virtual double SquareArea();
        virtual void PritInfo();
};  

double CTriAngle:: SquareArea()
{
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void CTriAngle:: PritInfo()
{
    cout << "CTriAngle"<<SquareArea()<<endl;
}

//定义指针数组
CGeometry* pGeometry[100];

//s1 s2指向CGeometry内带比较的元素，指针类型
int MyCompare(const void* s1 ,const void* s2)
{
    double a1,a2;   //存储求得的面积大小
    CGeometry* *p1; //不可以直接写*s1 来获取待比较的对象 因为s1 的类型为void* 类型
    CGeometry* *p2; //s1 为CGeometry内的原始类 CGeometry* 类型，p1 p2 指向指针的指针 CGeometry**类型
    p1 = (CGeometry**)s1; //p1是基类的指针的指针，指向基类的指针
    p2 = (CGeometry**)s2;
    a1 = (*p1) -> SquareArea();//多态，若p1指向CRect类，则调用CRect::SquareArea()
    a2 = (*p2) -> SquareArea();
    if (a1<a2)
        return -1;
    else if (a2 < a1)
        return 1;
    else 
        return 0;
}
//多态的作用
//当添加新的几何形状时，只需要更改输入和添加新的几何类
//通常使用基类指针数组存放指向各个派生类的指针
//遍历数组就能对各个派生类进行操作
int main(int argc, char const *argv[])
{   
    CRect*      pRect;
    CCircle*    pCircle;
    CTriAngle*  pTriAngle;
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        char c;
        cin >>c;
        switch(c)
        {
            case'R':
                pRect = new CRect();
                cin >> pRect->w>>pRect->h;
                pGeometry[i] = pRect;
                break;
            case'C':
                pCircle = new CCircle();
                cin >> pCircle->r;
                pGeometry[i] = pCircle;
                break;
            case'T':
                pTriAngle = new CTriAngle();
                cin >> pTriAngle->a >> pTriAngle->b >> pTriAngle->c;
                pGeometry[i] = pTriAngle;
                break;            

        }
    }

    qsort(pGeometry,n,sizeof(CGeometry*),MyCompare);
    for(int i=0;i<n;i++)
    {
        //多态，通过指针指向的对象决定调用的函数
        pGeometry[i]->PritInfo();
    }
    system("pause");
    return 0;
}
