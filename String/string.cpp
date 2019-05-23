//模板类
//typedef basic_string<char> string;
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //初始化
    std::string s1("hello");
    string month = "march";
    string s2(8,'x');
    //成员函数
    cout << s1.length();
    //读取
    string s3;
    cin >> s3;
    //getline
    string s4;
    getline(cin,s4);
    //赋值和连接
    string s6("cat"),s5;
    s5 = s6;
    //assign 赋值
    s6.assign(s5);
    s6.assign(s5,1,3);//从1开始的3个字符
    //单字符赋值
    s5[3] = s6[1] = 'a';
    //遍历string
    for(int i=0;i<s5.length();i++)
    {
        //at的好处是会做范围检查，不会越界
        cout << s5.at(i) << " ";
        cout << s5[i] << " ";
    }    
    //连接
    s1 = s1 + s2 ;
    s1.append(s2);
    //若字符个数不够，则添加到s2的结尾为止
    s1.append(s2,3,s2.size());

    //String 的比较
    s1 > s2;
    s1 <= s2;
    //compare返回值 -1 0 1
    s1.compare(s2);
    //s1 从1开始的2个字符，和s3从0开始的3个字符比较
    s1.compare(1,2,s3,0,3);


    //String 的字串
    //从4开始的5个字符串
    s1.substr(4,5);

    //交换
    s1.swap(s2);
    
    //find查找,返回下表，找不到返回string::npos
    s1.find("o");
    //指定从1位置开始找
    s1.find("o",1);
    //rfind，反向查找
    s1.rfind("o");
    //find_first_of，任意一个字符第一次出现的位置
    //查找字符
    s1.find_first_of("abdc");
    //第一次不在absc中的字符的位置
    s1.find_first_not_of("absc");
    //find_last_of()最后一次出现的地方
    s1.find_last_of("ab");


    //erase()，删除字符
    //5以后的都删掉
    s1 = "Hello World";
    s1.erase(5);

    //replace() 替换
    //3位置开始，4个字符替换掉
    //s1中去掉4个字符，替换的字符全部添加进去
    s1.replace(3,4,"asfasfa");
    s1.replace(3,4,"asfasfa",1,2);


    //insert    插入
    //4位置插入s2
    s1.insert(4,s2);
    s1.insert(4,s2,4,3);   

    //c_str(),返回const char* 指针,字符串以'\0'结尾
    s1.c_str();
    //data(),返回char* 类型的指针
    s1.data();

    system("pause");
    return 0;
}
