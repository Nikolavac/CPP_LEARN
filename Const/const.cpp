//常量指针可以为非常量指针赋值，反过来不行。
//常量指针倾向于不修改所指向的内容
//用于函数内部，防止参数被修改
// const 类型，具有独立类型
// 引用不能引用常量和表达式，只能引用变量
// 引用初始化后，一直引用该变量，不能引用其他变量
#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{   
    char name1[40],name2[40];
    cin.getline(name1,50);
    cin>>name1>>name2;
    cout<<name1<<endl;
    cout<<name2<<endl;
    cout<<"################"<<endl;
    cout<<endl;
    system("pause");
    return 0;
}
