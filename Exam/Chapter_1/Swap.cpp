/*
#include <iostream>
using namespace std;
class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(A &a,A &b)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
    system("pause");
	return 0;
}
*/
#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
int* &a ,int* &b
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
    system("pause");
	return 0;
}
