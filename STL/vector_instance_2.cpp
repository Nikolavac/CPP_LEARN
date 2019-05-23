//二维数组
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    //v里面3个元素，每个都是空的vector
    vector< vector<int> > v(3);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            v[i].push_back(j);
        }
    }


    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }


    system("pause");
    return 0;
}
