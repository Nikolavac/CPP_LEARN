//继承与复合关系
//B是A的派生类， 则一个B对象也是A对象  
//C中有成员变量k k是D的对象 则C和D是复合关系 D是C的组成部分
class CPoint 
{
    double x,y;
};

//复合关系，封闭类？

class CCircle
{
    double r;
    CPoint center;
};

class CMaster;
class CDog
{   
    //指针指向主人对象
    CMaster* pM;
};
class CMaster
{   
    //定义指针数组，成员变量为指针，指向狗的对象
    CDog* dogs[10];
};
