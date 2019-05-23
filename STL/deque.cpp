//顺序容器：双向队列
//push_front pop_front 复杂度O(1)
//双向链表
//成员函数
//push_front
//pop_front 
//sort      排序
//remove    删除和指定值相同的所有元素
//unique    sort后，删除和前一个元素相同的元素
//merge    合并，并清空某一个
//reverse  颠倒
//splice   在一个链表中删除某些元素，插入到另一个链表中某个位置
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class A
{
    private:
        int n;

    public:
        A(int n_):n(n_){}
        friend bool operator< (const A& a1,const A& a2);
        friend bool operator==(const A& a1,const A& a2);
        friend ostream& operator<< (ostream& o,const A& a);
};

bool operator<(const A& a1,const A& a2)
{
    return a1.n < a2.n; 
}

bool operator== (const A& a1,const A& a2)
{
    return a1.n == a2.n;
}

ostream&  operator<< (ostream& o,const A& a)
{
    o<<a.n;
    return o;
}

template<class T>
void PrintList(const list<T> &lis)
{
    //要求使用typename
    //在模板内定义类型不确定的迭代器，需要使用typename关键字声明
    typename list<T>::const_iterator i;
    for(i = lis.begin();i!=lis.end();i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}



int main(int argc, char const *argv[])
{
    list<A> lis1,lis2;
    lis1.push_back(1);
    lis1.push_back(2);
    lis1.push_back(3);
    lis1.push_back(4);
    lis1.push_back(2);

    lis2.push_back(10);
    lis2.push_back(20);
    lis2.push_back(30);
    lis2.push_back(30);
    lis2.push_back(30);
    lis2.push_back(40);
    lis2.push_back(40);

    cout<<"1>";
    PrintList(lis1);
    cout<<"2>";
    PrintList(lis2);

    lis1.sort();
    cout <<"3>";
    PrintList(lis1);

    lis2.pop_front();
    cout <<"4>";
    PrintList(lis2);

    //链表删除所有A(2)元素
    lis1.remove(2);
    cout <<"5>";
    PrintList(lis1);

    //lis2中删除与前一个元素相同的元素
    lis2.unique();
    cout <<"6>";
    PrintList(lis2);

    //合并
    lis1.merge(lis2);
    cout << "7>";
    PrintList(lis1);

    cout << "8>";
    PrintList(lis2);


    lis1.reverse();
    cout << "9>";
    PrintList(lis1);
//--------------------------------------------------------//
    lis2.push_back(100);
    lis2.push_back(200);
    lis2.push_back(300);
    lis2.push_back(400);


    list<A>::iterator p1,p2,p3;

    p1 = find(lis1.begin(),lis1.end(),3);
    p2 = find(lis2.begin(),lis2.end(),200);
    p3 = find(lis2.begin(),lis2.end(),400);

    //在[p2,p3)插入p1之前，并从lis2中删除[p2,p3)
    lis1.splice(p1,lis2,p2,p3);
    cout << "10>";
    PrintList(lis1);
    cout << "11>";
    PrintList(lis2);

    system("pause");
    return 0;
}
