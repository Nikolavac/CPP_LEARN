#include<iostream>
#include<iomanip>
using namespace std;

//设置位宽
//setw,width
//width是iostram的成员函数
//    cin >> setw(4);
//    cin.width(5);
//    cout << setw(4);
//    cout.width(5);

//宽度设置的有效性是一次性的，每次读取输出都要重新设定
int main(int argc, char const *argv[])
{   
    int w = 4;
    char string[10];
    //每次读入4个字符+'\0'
    cin.width(5);
    while(cin >> string)
    {
        cout.width(w++);
        cout << string << endl;
        cin.width(5);
    }
    system("pause");
    return 0;
}
