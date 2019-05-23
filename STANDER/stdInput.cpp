#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{

    int x;
    //判断流结束while(cin>>x)
    //>>返回值应该是cin&,但是通过强制类型转换值的重载运算，返回值也可以Bool形
    //crtl+Z表示输入结束
    //getline(char* buf,int bufsize);读取bufsize-1个字符到缓存区或'\n'结束
    //getline(char* buf,int bufsize,char delim);读取bufsize-1个字符到缓存区或delim结束

    //cin.eof
    //bool eof()    判断输入流是否结束
    //int peek()    返回下一个字符，但不会从流中去掉
    //istream& putback(char c);     将字符ch放回输入流
    //istream& ignore(int nCount = 1,int delim = EOF)   从流中删除最多nCount个字符，遇到EOF时结束(EOF= -1)

    char buf[100];
    cin >> x;//读取12
    cin.getline(buf,90);//包含空格一起读入buf
    cout << buf <<endl;
    system("pause");
    return 0;
}
