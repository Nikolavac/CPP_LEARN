#include<iostream>
#include<regex>
using namespace std;

int main(int argc, char const *argv[])
{
    //正则表达式
    //.?表示任意字符出现0次或1次
    //.*表示前面出现的字符穿出现一次或0次
    regex reg("b.?p.*k"); 
    cout << regex_match("bopggk",reg) << endl;
    cout << regex_match("boopgggk",reg) << endl;
    cout << regex_match("b pk",reg) << endl;

    // /d表示数字
    // {3}表示出现3次
    // ()表示一项并不参与匹配
    // []
    // a-zA-Z表示英文单次
    // + 表示前面出现1次或若干次
    // . 表示任意字符
    // | 表示或
    // \s 表示空格
    // 
    regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
    string correct = "123Hello N/A Hello";
    string incorrect = "123Hello 12 hello";
    cout << regex_match(correct,reg2)<<endl;
    cout << regex_match(incorrect,reg2) << endl;

    system("pause");
    return 0;
}
