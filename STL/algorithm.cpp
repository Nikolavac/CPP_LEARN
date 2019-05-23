#include<vector> 
#include<algorithm>
#include<iostream>
using namespace std;

//算法通过迭代器对容器进行操作，可以对容器的某个区间进行处理
//find:顺序查找
//template<class Inlt,class T>
//Inlt find(Inlt first,Inlt last,const T& val);
//[first,end)查找区间
// == 来判断，可以重载
// 返回迭代器，找不到迭代器等于last(查找区间里面的last)


int main(int argc, char const *argv[])
{

    int array[10] = {10,20,30,40};  
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>:: iterator i;
    //v.end()不在查找区间内
    //没有找到时，返回的迭代器是find查找区间的最后一个，不是容器的最后一个
    i = find(v.begin(),v.end(),3);
    if(i != v.end())
    {
        cout << *i;
    }

    i = find(v.begin()+1,v.end()-2,1);

    //普通数组
    int *pp = find(array,array+4,20);
    cout << *pp;

     
    system("pause");
    return 0;
}
