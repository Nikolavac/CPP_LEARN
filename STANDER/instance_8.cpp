#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
    char name[20];
    int  score;
};
//二进制文件读写

int main(int argc, char const *argv[])
{
    //写文件
    Student s;
    ofstream OutFile("STANDER/student.dat",ios::out|ios::binary);
    while(cin >> s.name >> s.score)
    {
        OutFile.write( (char*) &s,sizeof(s));
    }
    OutFile.close();

    //读文件
    ifstream SrcFile("STANDER/student.dat",ios::in|ios::binary);
    if(!SrcFile)
    {
        cout << "Open error" << endl;
        return 0;
    }

//SrcFile.read 返回值是istream&, 但是重载为bool型
    while(SrcFile.read((char*) &s,sizeof(s)))
    {
        //可能读的不够 readBytes <= sizeof(s)
        int readBytes = SrcFile.gcount();//记录读取字节数
        cout << s.name << " " << s.score << endl;
    }


    system("pause");
    return 0;
}
