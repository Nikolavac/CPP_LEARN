#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student 
{
    public:
        int  Age;
        int  Id;
        int  score[4];
        int  average;
        char name[];
        void input();
        void calculate();
        void output();
};

void Student::input()
{
    char m[50];
    gets(m);
    int i=0;
    while(m[i] != '\0')
    {
        for(;;i++)
        {
            
        }
    }
}

void Student::calculate()
{   
    int TempScore = 0;
    for(int i=0;i<4;i++)
    {
        TempScore += score[i];
    }
    average = TempScore/4;
}

void Student::output()
{
    cout<<name<<Age<<Id<<average<<endl;
}
int main() 
{
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
    system("pause");
}