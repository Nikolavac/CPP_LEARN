#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

//动态可变数组
class CArray
{
    private:
        
    public:
        int num;
        int* pArray;
        //构造函数
        //CArray(){};
        //包含默认值的构造函数，可以省去写无参构造函数
        CArray(int length = 0);
        //拷贝构造函数,这里可以使用常引用
        CArray(const CArray& a);
        //析构函数
        ~CArray();
        //重载函数
        CArray& operator= (const CArray& a);
        //返回值类型 int&
        //非引用的函数返回值不能作为等号的左值使用
        int& operator[] (int i)
        {   
            //n = a[i] , a[i] = 4
            return pArray[i];
        }
        int length(){return num;}
        void push_back(int x);                                                                  

};
//构造函数，参数列表初始化方式
CArray::CArray(int length):num(length)
{
    if(length == 0)
    {
        pArray = NULL;
    }
    else
    {
        pArray = new int[length];
    }

}
//必须写拷贝构造函数，否则将使得新对象与旧对象指向同一地址
//深拷贝
CArray::CArray(const CArray& a)
{
    if( a.pArray == NULL )
    {
        pArray = NULL;
        num = 0;
        return ;
    }
    pArray = new int[a.num];
    memcpy(pArray,a.pArray,sizeof(int)*a.num);
    num = a.num;
}
//析构函数
CArray::~CArray()
{
    if(pArray)
    {
        delete [] pArray;
    }
}

//返回引用类型
CArray& CArray::operator= (const CArray& a)
{   
    //防止A=A
    if(pArray == a.pArray)
    {
        return *this;
    }
    //如果A为空
    if(a.pArray == NULL)
    {   
        //原本不为空，delete
        if(pArray)
        {
            delete [] pArray;
        }
        pArray = NULL;
        num = 0;
        return *this;

    }
    //存储空间不够
    if(num < a.num)
    {
        if(pArray)
        {
            delete [] pArray;
        }
    }
    pArray = new int[a.num];
    memcpy(pArray,a.pArray,sizeof(int)*a.num);
    num = a.num;
    return *this;
}


void CArray::push_back(int v)
{
    if(pArray)
    {
        int* TempPArray = new int[num+1];
        memcpy(TempPArray,pArray,sizeof(int)*num);
        delete [] pArray;
        pArray = TempPArray;
    }
    else
    {
        pArray = new int[1];
    }
    pArray[num++] = v;

}


//--------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{   
    CArray a;
    for(int i=0;i<5;i++)
    {
        a.push_back(i);
    }
    
    CArray a2,a3;
    a2 = a;
    for(int i=0;i<a2.length();i++)
    {
        cout << a2[i] <<" ";
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for(int i=0;i<a4.length();i++)
    {
        cout << a4[i] << " ";
    }
   
    system("pause");
    return 0;
}
