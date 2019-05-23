#include<iostream>
#include<vector>
using namespace std;


//迭代器
//定义：
//容器名:: iterator 变量名
//容器名:: const_iterator 变量名  
//访问：
//*迭代器变量名
//操作：
//++,若到达最后一位再++则出错

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //迭代器
    vector<int>::const_iterator i;
    //v.begin 返回第一个元素的迭代器，指向第一个元素
    //v.end   返回最后一个元素后一个位置的迭代器
    //++i 与重载有关
    for (i = v.begin();i != v.end();++i)
    {   
        //访问方式*i
        cout << *i << endl;
    }
    //反响迭代器,与普通迭代器不相同，类型也不兼容
    vector<int>::reverse_iterator r; 
    //此时r++会指向前一个元素
    for(r=v.rbegin();r!=v.rend();r++)
    {
        cout << *r << endl;
    }

    //通过*j修改容器内元素的值
    vector<int>::iterator j;
    for(j=v.begin();j != v.end();j++)
    {   
        *j = 100;
    }

    for (i = v.begin();i != v.end();++i)
    {   
        //访问方式*i
        cout << *i << endl;
    }

//双向迭代器和随机访问迭代器
//双向迭代器操作：++p p++ --p p-- *p p = p1  p==p1 p!=p1
//随机访问迭代器：双向操作、 p+=i p-=i (移动)  p+i(返回迭代器，p后面的第i个元素)  p[i](p后面第i个元素的引用)  <(比较位置)  >=


//vector deque 随机访问迭代器
//list set/multiset  map/multimap 双向迭代器
//stack queue priority_queue 不支持迭代器


    system("pause");
    return 0;
}

 