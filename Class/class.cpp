#include "iostream"
using namespace std;

// 成员变量和成员函数统称为成员
// Rectangle 是用户自定义类型
// 【对象】占用的内存大小是全部成员变量的大小之和
// 对象有自己的存储空间
class Rectangle
{
    public:
        int w,h;
        int Area(){return w*h;}
        int Perimeter(){return 2*(w+h);}
        void Set(int w_,int h_)
        {
            w = w_;
            h = h_;
        }

};

void PrintRectangle(Rectangle &r)
{
    cout<<r.Area()<<endl;
}

int main(int argc, char const *argv[])
{
    int w,h;
    Rectangle r; // r是对象

    //通过引用指向对象
    Rectangle R2;
    // rr为R2的引用
    Rectangle &rr = R2;
    //通过rr改变R2的值
    rr.w =5;
    rr.Set(4,5);
    PrintRectangle(rr);
    //输出
    cin>>w>>h;
    r.Set(w,h);
    cout<<r.Area()<<endl;
    cout<<r.Perimeter()<<endl;
    //通过指针指向对象
    Rectangle *p1 = &r;
    cout<<p1->Area()<<endl;
    system("pause");
    return 0;
}
