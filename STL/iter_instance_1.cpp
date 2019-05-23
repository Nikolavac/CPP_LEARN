#include<vector>
#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> v(100);
    int i;
    for(i=0;i<v.size();i++)
    {
        cout << v[i];//随机访问
    }

    vector<int>::const_iterator ii;
    //v.end()返回迭代器，可以通过！= 比较
    for(ii = v.begin();ii!=v.end();i++)
    {
        cout << *ii;
    }
    //随机访问迭代器，可以 < 比较
    for(ii = v.begin();ii < v.end();i++)
    {
        cout << *ii;
    }

    //随机访问迭代器，可以 < 比较
    for(ii = v.begin();ii < v.end();i++)
    {
        cout << *ii;
        //随机访问迭代器，可以+= 操作 
        ii += 2;
    }

    return 0;
}
