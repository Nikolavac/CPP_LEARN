#include<iostream>
#include<iomanip>
using namespace std;

//位宽设置一次性的
int main(int argc, char const *argv[])
{
    int n = 124;
    cout << "1>" << hex << n << " " << dec << n << " " << oct << n << endl;
    double x = 1234567.89,y = 12.34567;
    cout << "2>" << setprecision(5) << x << " " << y << " "<< endl;
    cout << "3>" << fixed << setprecision(5) << x << " " << y << " " << endl;
    cout << "4>" << scientific << setprecision(5) << x << " " << y << endl; 
    //showpos 显示正号
    cout << "5>" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
    //不显示正号,左对齐
    cout << "6>" << noshowpos << setw(12) << left << 12.1 << endl;
    cout << "7>" << setw(12) << right << 12.1 << endl;
    cout << "8>" << setw(12) << internal << -12.1 << endl;
    cout << "9>" << 12.1 << endl;
    system("pause");
    return 0;
}
