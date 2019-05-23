//类模板
#include<iostream>
using namespace std;


template <class T1,class T2>
class Pair
{
    public:
        T1 key;
        T2 Value;
        Pair(T1 k,T2 v):key(k),Value(v){}
        bool operator < (const Pair<T1,T2> &p) const;
};
//写类型参数表
template<class T1,class T2>
//此时类的名字要带着类型参数表
bool Pair<T1,T2>::operator< (const Pair<T1,T2>& p) const
{
    return key < p.key;
}

int main(int argc, char const *argv[])
{
    //模板类的实例化方式:
    Pair<string , int > student("Tom",19);
    cout << student.key << " " << student.Value<< endl;
    system("pause");
    return 0;
}
