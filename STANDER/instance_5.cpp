#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

//文件读写
//ios::out 文件打开方式
//ios::out 输出文件，删除原文件
//ios::app 输出文件，保持原文件在尾部添加
//ios::binary 二进制打开
//ofstream outFile("STANDER/Test_2.txt",ios::out|ios::binary);

//文件的读写指针，表示文件操作的当前位置
int main(int argc, char const *argv[])
{
    //创建ofstream对象
    ofstream fout;
    if(!fout)
    {
        cout << "Error" << endl;
    }
    
    fout.open("STANDER/Test_2.txt",ios::app);
    //写指针位置
    long location = fout.tellp();
    //location可以为负值
    location = 10;
    fout.seekp(location);     //指针移到第10个字节处
    fout.seekp(location,ios::beg); //从头数
    fout.seekp(location,ios::cur); //从当前位置
    fout.seekp(location,ios::beg); //从尾

    //读文件,ate表示文件尾部
    ifstream fin("STANDER/Test_2.txt",ios::ate);
    //文件的读指针tellg(),当读指针在文件尾部时，tellg()获得的为文件长度
    long location = fin.tellg();
    location = 10;
    fin.seekg(location);
    fin.seekg(location,ios::beg); //从头数
    fin.seekg(location,ios::cur); //从当前位置
    fin.seekg(location,ios::beg); //从尾

    
    system("pause");
    return 0;
}
