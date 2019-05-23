//析构函数，函数名与类名相同，在前面加~ 没有参数和返回值
//一个类最多有一个析构函数
//在对象消亡时自动调用，默认的析构函数什么都不做


#include <iostream>
using namespace std;


class String
{
    private:
        char *p;
    public:
        String()
        {
            p = new char[10];
            cout<<"Constructor Called"<<endl;
        }
        ~String();
};
String::~String()
{
    delete [] p;
    cout << "Destructor called"<<endl;
}

//析构函数在函数的返回值为对象时，也会被调用
//在函数的形参为对象时，也会调用
String Func(String Tem)//首先调用拷贝构造函数，生成新参对象
{   //调用析构函数，释放形参对象
    return Tem;
}
int main(int argc, char const *argv[])
{
    //对象数组的每一个元素均会调用析构函数
    String array[2];
    String *p;
    *p = Func(*p);//调用拷贝构造函数，给*p赋值，赋值结束后，临时对象调用析构函数 
    p = new String; // 调用构造函数
    delete p;  //调用析构函数
    p = new String[3]; //调用三次构造函数
    delete []p ; //调用三次析构函数
    cout << "main_end"<<endl;
    system("pause");
    return 0;
}
