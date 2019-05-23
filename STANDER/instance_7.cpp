#include<iostream>
#include<fstream>

using namespace std;
//二进制文件读写
//istream& read(char* s,long n)
//从文件读指针的位置读n个字节的内容到内存地址s,同时将指针移动n字节(ios::in,读指针指向文件开头)
//二进制写文件
//istream& write(const char* s,long n)
//把s出的n字节内容写到写指针所指位置，同时将写指针移动n字节
//ios::out写指针指向文件开头
//ios::app写指针位于文件尾部
int main(int argc, char const *argv[])
{
    //二进制读文件
    ofstream fout("STANDER/some.dat",ios::out|ios::binary);
    int x = 123;
    fout.write((const char*)(&x),sizeof(int));
    fout.close();
    ifstream fin("STANDER/some.dat",ios::in|ios::binary);
    int y;
    fin.read((char*) &y,sizeof(int));
    fin.close();
    cout << y << endl;
    system("pause");
    return 0;
}
