#include<string>
#include<iostream>
#include<sstream>
using namespace std;
//以字符串作为输入的来源

int main(int argc, char const *argv[])
{
    string input("Input test 123 4.7 A");
    istringstream inputString(input);
    string String1,String2;
    int i;
    double d;
    char c;
    inputString >> String1 >> String2 >> i >> d >> c;
    cout << String1 << String2 << endl;
    cout << i << endl << d << endl << c << endl;
    long l;
    if(inputString >> l)
    {
        cout << "long\n";
    }
    else
    {
        cout << "empty";
    }


    ostringstream outString;
    int a= 10;
    outString << "This" << a << "ok" << endl;
    //outString 的字符串
    cout << outString.str();
    system("pause");
    return 0;
}
