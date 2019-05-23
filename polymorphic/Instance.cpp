#include<iostream>
using namespace std;


//具体的实现，可以通过基类的指针指向具体的对象来实现多态
//有可以是函数的形参为基类的指针，但是传入其他派生类的引用来实现多态
class CCreature
{
    protected:
        int nPower;
        int nLifeValue;
    //在基类中定义虚函数
    public:
        virtual void Attack(CCreature* pCreature);
        virtual void Hurted(int nPower);
        virtual void FightBack(CCreature* pCreature);
};
class CWolf;
class CDragon:public CCreature
{
    public:
    //无虚函数，则传入不同类型，需要重载
    //重载虚函数是为了定义不同的反击动作等
        virtual void Attack(CCreature* pCreature);
        virtual void Hurted(int nPower);
        virtual void FightBack(CCreature* pCreature);
};
//注意，这里必须是派生类，才能是多态
//基类与派生类的同名虚函数，才存在多态
class CWolf:public CCreature
{
    public:
    //无虚函数，则传入不同类型，需要重载
        virtual void Attack(CCreature* pCreature);
        virtual void Hurted(int nPower);
        virtual void FightBack(CCreature* pCreature);
};

void CDragon::Attack(CCreature* p)
{   
    //形参是基类的指针，但实参是CWolf对象的指针
    //P指向CWolf的对象，则调用CWolf的Hurted函数
    //根据多态的原则，这里调用将是CWolf内的虚函数
    p->Hurted( nPower);//多态
    p->FightBack(this);//多态
}

int main(int argc, char const *argv[])
{
    CDragon d,s;
    CWolf w;
    //派生类的指针可以给赋值给基类的对象
    //传入的是派生类的对象指针，则调用的是
    d.Attack(&w);
    system("pause");
    return 0;
}
