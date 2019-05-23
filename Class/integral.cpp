#include<iostream>
using namespace std;



class Demo
{
    private:
        int id;
    public:
        Demo(int i)
        {
            id = i;
            cout <<"id = "<<id<< " constructor Called" <<endl;
        }
        ~Demo()
        {
            cout<<"id = "<<id<< " destructor Called" <<endl;
        }
};

void Func()
{
    static Demo d2(2);//静态局部变量，第一次时进行初始化，函数退出时维持原有值，直到程序结束
    Demo d3(3);//局部对象建立，并消亡
    cout<<"Func end"<<endl;
}

Demo d1(1); //全局变量，在mian开始前初始化

int main(int argc, char const *argv[])
{
    Demo d4(4);
    // 生成临时对象，调用构造函数，id =6 Constructor 
    // 赋值结束后，调用析构函数，释放临时对象 id = 6 Destructor 
    d4 = 6;// 通过类型转换构造函数，生成临时对象赋值给d4
    cout << "Main"<<endl;
    {Demo d5(5);}
    Func();
    cout << "Main End"<<endl;
    system("pause");
    // 一般来说先初始化先构造的先消亡
    return 0;
}
//New 产生的对象不delete 则不调用析构函数
