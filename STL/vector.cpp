#include<iostream>
#include<vector>
using namespace std;
template<class T>
//这里传入的是两个迭代器
void PrintVector(T s,T e)
{   
    for(;s != e; ++s)
    {
        cout << *s << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,5};
    //重载了构造函数
    vector<int> v(a,a+5);

    cout << "1>" << v.end() - v.begin() << endl;

    cout << "2>";
    PrintVector(v.begin(),v.end());

    //插入
    v.insert(v.begin()+2,13);
    cout <<"3>";
    PrintVector(v.begin(),v.end());

    //删除
    v.erase(v.begin()+2);
    cout <<"4>";
    PrintVector(v.begin(),v.end());

    //4个100
    vector<int> v2(4,100);
    //插入的重载
    //在开头插入1到3的元素
    v2.insert(v2.begin(),v2.begin()+1,v.begin()+3);
    cout <<"5>";
    PrintVector(v.begin(),v.end());

    //删除
    v.erase(v.begin()+1,v.begin()+3);
    cout <<"6>";
    PrintVector(v.begin(),v.end());
    

    system("pause");
    return 0;
}
