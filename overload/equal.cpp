#include<iostream>
#include<cstring>
using namespace std;

//赋值运算符重载，运算符两边的类型可以不匹配
//只能重载为成员函数

class CString
{
    private:
        char* str;
    
    public:
        CString():str(new char[1]){str[0] = 0;}
        const char* c_str() {return str;}
        CString & operator= (const char* s);
        ~CString() {delete[] str;}
};     

//返回对象的引用
CString& CString:: operator= (const char* s)
//使得OBJ = "hello"
{
    delete [] str; 
    str = new char[strlen(s)+1];
    strcpy(str,s);
    return *this;
}


int main(int argc, char const *argv[])
{
    CString s;
    s = "hello";
    cout << s.c_str() <<endl;
    //CString c2 = "hello" 会出错，这是一条初始化语句，没有定义构造函数参数为char*类型

    system("pause");
    return 0;
}
