#include<iostream>
#include<fstream>
using namespace std;

//文件拷贝
int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        cout << "File name Missing"<<endl;
        return 0;
    }

    ifstream SrcFile(argv[1],ios::binary|ios::in);
    if (!SrcFile)
    {
        cout << "Open Error" << endl;
        return 0;
    }

    ofstream DestFile(argv[2],ios::out|ios::binary);
    if (! DestFile)
    {
        cout << "Open Destination File Error" << endl;
        //注意关闭打开的文件
        SrcFile.close();
        return 0;
    }
    char c;
    while(SrcFile.get(c) )//读取一个字节
    {
        DestFile.put(c);
    }
    DestFile.close();
    SrcFile.close();
    return 0;


    system("pause");
    return 0;
}
