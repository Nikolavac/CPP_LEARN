//继承和派生
#include<iostream>
using namespace std;
//派生类可以继承基类的private成员函数和变量，
//但是派生类的成员函数不能访问基类的private   
//派生类的内存空间   基类的体积加自身的体积 派生类对象包含基类对象
// 基类的存储位置位于新增成员变量之前
class CStudent
{
    private:
        string sName;
        string Id;
        char gender;
        int nAge;
    public:
    //参数列表只能用于构造函数，先于构造函数执行
        void PritfInfo()
        {
            cout << sName << Id <<gender <<nAge<<endl;
        }
        void SetInfo(const string& name_,const string& id_, int age_, char gender_)
        {
            sName = name_;
            Id = id_;
            nAge = age_;
            gender = gender_;
        }
        string GetName(){return sName;}
        bool IsThreeGood();
        void SetName(const string& Name)
        {
            sName = Name;
        }

};
//派生类 类名：public 基类名
class CUndergraduStudent : public CStudent
{
    private:
        string nDepartment;
    public:
        void Qualifed()
        {
            cout << "qualified for BY"<<endl;
        }
        void PritfInfo()
        {   
            CStudent::PritfInfo();//基类的pritfInfo
            cout << "Department"<<nDepartment<<endl;
        }
        void SetInfo(const string& name_,const string& id_, int age_, char gender_,const string& nDepartment_)
        {   
            //基类的setInfo
            CStudent::SetInfo(name_,id_,age_,gender_);
            nDepartment = nDepartment_;
        }
        bool IsThreeGood();     //覆盖
        bool CanBaoYan();
};
class CGraduatedStudent : public CStudent
{
    private:
        int nDepartment;    
        char szMentor[20];
    public:
        int CountSalary();
};
int main(int argc, char const *argv[])
{
    CUndergraduStudent s2;
    s2.SetInfo("H","122313",19,'M',"Computer");
    cout << s2.GetName() <<endl;
    s2.Qualifed();
    s2.PritfInfo();

    system("pause");
    return 0;
}
