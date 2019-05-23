#include<iostream>
using namespace std;


//常量对象
//常量成员函数，不应该修改成员变量的值（静态成员除外），
//也不可调用非常量成员函数（静态函数除外）
//保持对象的值不变

class Demo
{   
    //存在私有变量，则默认的无参构造函数失效了
    private:
        //int value;
    public:
        void SetValue();
};

class Sample
{
    public:
        int value;
        //GetValue 算常量函数的重载
        void GetValue() const;
        void GetValue();
        void func(){}
        void Print(Sample &o);
        Sample(){}
};

void Sample::GetValue() const
{
    //value = 0 ;//Wrong
    //func();//Wrong
    cout << "Const" << endl;
    return ;
}

void Sample::GetValue()
{
    cout<<"No Const"<<endl;
}

int main(int argc, char const *argv[])
{
    const Demo b;
    const Sample o;
    Sample o1;

    //o.value = 100;  常量对象的值不可被修改
    //o.func();        常量对象不可执行非常量成员函数
    // 常量对象执行GetValue() const
    o.GetValue();
    //非常量对象执行GetValue()
    o1.GetValue();
    //常引用，不能通过常引用改变所引用的变量
    int n;
    const int &r =n;
    //r=5;Error
    n =4;
    //常引用作为参数，用对象做函数的参数需要调用拷贝构造函数，产生开销。
    //使用指针作为参数，代码不好看
    //可以使用引用作为参数
    // void Print(Sample &o) , o会修改实参
    // Void Print(const Sample &o) 修改o编译器将报错
    system("pause");    
    return 0;
}
