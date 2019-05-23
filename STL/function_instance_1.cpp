#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;

//函数对象

int SumSquares(int total,int value)
{
    return total += value*value;
}

template <class T>
void Printinterval(T first,T last)
{
    for(;first!=last;++first)
    {
        cout << *first<<" ";
    }
    cout << endl;
}

template <class T>
class SumPowers
{
    private:
        int power;
    public:
        SumPowers(int power_):power(power_){}
        //函数对象必须重载()
        const T operator() (const T& total,const T& value)
        {
            T v = value;
            for(int i=0;i<power-1;++i)
            {
                v = v*value;
            }
            return total+v; 
        }
};


template <class T,class Pred>
//op 可以是函数指针，也可以是函数对象
//返回迭代器
T MyMax(T first,T last,Pred op)
{
    T tempMax = first;
    for(;first!=last;++first)
    {
        if(op(*tempMax,*first))
        {
            tempMax = first;
        }
    }
    return tempMax;
}


int main(int argc, char const *argv[])
{
    const int SIZE = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a,a+SIZE);
    cout << "1>";
    Printinterval(v.begin(),v.end());
    cout << endl;

    //<int>类模板的实例化 (3)表示对象初始化
    //总的来说，这是一个对象
    //accumulate(iter iter init *op(int,int))
    //{init = op(init,int);return init;}
    //*op是一个函数指针

    int result = accumulate(v.begin(),v.end(),0,SumSquares);
    cout <<"2>" <<" "<< result << endl;

    //accumulate(iter iter init SumPower<int> op)
    //函数模板的作用可以传入参数
    result = accumulate(v.begin(),v.end(),0,SumPowers<int>(3));
    cout <<"3>" <<" "<< result << endl;
    result = accumulate(v.begin(),v.end(),0,SumPowers<int>(4));
    cout <<"4>" <<" "<< result << endl;



    //list 排序
    //great<int> 类模板的实例化  ()表示无参构造函数
    //比较时， x<y <=> op(x,y) 为True
    //lst.sort(great<int>())

 
    system("pause");
    return 0;
}
