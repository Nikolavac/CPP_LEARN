#include<iostream>
#include<cstring>
using namespace std;
//深拷贝与浅拷贝
class CString
{
    private:
        char* str;
    public:
        CString():str(new char[1]){str[0] = '\0';}
        const char* c_str() {return str;}
        //避免指向同一存储空间
        
        CString& operator= (const char* c)
        {   
            delete [] str;
            str = new char[strlen(c)+1];
            cout <<"Initial Condition"<<endl;
            strcpy(str,c);
            return *this;
        }
        

        CString& operator= (const CString& c)
        {   
            if( this == &c )
            {
                return *this;
                cout<<"Equal Condition"<<endl;
            }
            delete [] str;
            str = new char[strlen(c.str)+1];
            strcpy(str,c.str);
            cout<<"Alter Condition"<<endl;
            return *this;
        }

        //缺省的拷贝构造函数，会导致两个对象赋值的过程中，将两个对象指向同一片内存空间
        CString(CString& a)
        {
            str = new char[strlen(a.c_str())+1];
            strcpy(str,a.c_str());
        }


        ~CString(){delete [] str;}

};


//返回值
//CString& 这样比较好
//(a=b)=c ()返回a的引用


int main(int argc, char const *argv[])
{
    CString s1,s2;
    s1 = "this";
    s2 = "malloc";
    //如果等号没有重载
    //s1 new出来的内存空间，不能被delete删除
    //s1 s2指向同一个地方，则s1被析构函数delete 若s2析构时则可能出现问题
    s1 = s2;
    //s1 = s1 重载等号的时候，会先delete s1 的存储空间
    s1 = s1;
    cout<<s1.c_str()<<endl;
    system("pause");
    return 0;
}
