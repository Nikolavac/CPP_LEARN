#include<iostream>
using namespace std;

//重定向文件读取

int main(int argc, char const *argv[])
{
    int x,y;
    cin>>x>>y;

    freopen("STANDER/Test.txt","w",stdout);//将标准输出重定向到test.txt文件
    freopen("STANDER/Test.txt","r",stdin);//输入重定向
    cin>>x>>y;
    if(y=0)
    {
        cerr << "error" << endl;
    }
    else
    {
        cout << x/y;
    }
    system("pause");
    return 0;
}
