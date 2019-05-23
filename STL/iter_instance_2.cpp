#include<list>
#include<iostream>
using namespace std;


//注意，这里list是链表，为双向迭代器，不可通过< 来比较end()返回的迭代器
//同时这里[]并没有重载的定义
int main(int argc, char const *argv[])
{
    list<int> l;
    list<int>::const_iterator i;
    for(i = l.begin();i!=l.end();++i)
    {
        cout << *i;
    }
    return 0;
}
