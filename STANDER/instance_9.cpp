#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct Student
{
    char name[20];
    int  score;
};
//二进制文件读写
//二进制文件大小固定便于查找


int main(int argc, char const *argv[])
{
    Student s;
    fstream iofile("STANDER/Student.dat",ios::in|ios::out|ios::binary);
    if (!iofile)
    {
        cout << "Error" << endl;
        return 0;
    }
    //从文件开始算ios::beg 2*sizeof(s)这么长数据
    iofile.seekp(2*sizeof(s),ios::beg);
    iofile.write("Mike",strlen("Mike")+1);
    //读指针定位为开头
    iofile.seekg(0,ios::beg);
    while(iofile.read((char*)&s,sizeof(s)))
    {
        cout << s.name << " " << s.score << endl;
    }
    iofile.close();
    system("pause");
    return 0;
}
