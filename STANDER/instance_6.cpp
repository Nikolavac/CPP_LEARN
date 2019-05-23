#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    ifstream SrcFile("STANDER/in.txt",ios::in);
    ofstream DestFile("STANDER/out.txt",ios::out);
    if(SrcFile)
    {
        cout << "Open Success" << endl;
    }
    int x;
    while( SrcFile >> x)
    {
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        //ostream的派生类的对象，<<已经重载过，可以输出到文件
        DestFile << v[i] << " ";
    }
    DestFile.close();
    SrcFile.close();
    system("pause");
    return 0;
}
