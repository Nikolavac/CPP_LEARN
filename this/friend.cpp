#include<iostream>
using namespace std;


//友元函数和友元类,普通函数与类关系密切
//一个类的友元函数可以访问类的私有成员，这个函数可以是全局函数
//友元关系不能传递，不可继承
class CCar;
class CDriver
{
    public:
        CCar Mycar;
        void ModifyCar(CCar* pCar);
        int  GetValue(CCar* pCar);
         
};

class CCar
{
    private:
        int price;
    //传入CCar 类型的数组
    friend int MostExpensiveCar(CCar cars[], int total);//友元函数
    friend void CDriver::ModifyCar(CCar* pCar);//友元函数
    friend class CDriver; //友元类
};

//可以访问CCar的私有成员变量
void CDriver::ModifyCar(CCar* pCar)
{   
    //指针使用->访问成员变量
    pCar->price += 1000;
}

//全局函数也可以访问Ccar的私有成员变量
int MostExpensiveCar(CCar cars[], int total)
{
    int tempMax = -1;
    for (int i=0;i< total;++i)
    {
        if (cars[i].price > tempMax)
        {
            tempMax = cars[i].price;
        }
    }
    return tempMax;
}


//友元类，如果A是B的友元类，则A的成员函数可以访问B的成员变量

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
