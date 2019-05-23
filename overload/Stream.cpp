#include<iostream>
#include<string.h>
using namespace std;
//流插入运算符和流提取运算符的重载
//iostream 中对<< 进行了重载
//void iostream::operator<< (int n )
//{
//      printf('n');
//      return;
//}
// iostream& iostream::<<(int n)
//{return *this;}

class CStudent
{
    private:
        int s;
    public:
        void setValue(int i);
        CStudent(int i=0):s(i){};
    
    friend ostream& operator<< (ostream& o,const CStudent& s);
    
};

class CComplex
{
    public:
        double real,imag;
        CComplex(double r,double i):real(r),imag(i){};
        CComplex(){};
    friend ostream& operator<< (ostream& o,const CComplex& c);
    friend istream& operator>> (istream& o, CComplex& c);
};


void CStudent::setValue(int i)
{
    s = i;
}

//返回引用类型，省略了拷贝构造函数的开销
ostream& operator<< (ostream& o,const CStudent& s)
{
    o<<s.s;
    return o;
}    


//返回引用类型，省略了拷贝构造函数的开销
ostream& operator<< (ostream& o,const CComplex& c)
{
    o<<c.real<<"+"<<c.imag<<"j";
    return o;
}    
 istream& operator>> (istream& is ,CComplex& c)
 {
     string s;
     is >>s;
     int pos = s.find("+",0);
     string sTemp = s.substr(0,pos);
     c.real = atof(sTemp.c_str());
     sTemp = s.substr(pos+1,s.length() - pos -2);
     c.imag = atof(sTemp.c_str());
     return is;
 }


int main(int argc, char const *argv[])
{   
    /*
    CStudent ss;
    CStudent ss1(3);
    ss.setValue(5);
    cout << ss1 << "hello";
    */
    CComplex c;
    int n;
    cin>>c>>n;
    cout<<c<<","<<n;
    system("pause");
    return 0;
}
