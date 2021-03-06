//容器、迭代器、算法
//容器：通用的数据结构
//迭代器：指针
//算法：函数

//---------------------------------------------//
//int array[100]  容器
//int* p          迭代器
//sort            算法
//sort(array,array+70);
//---------------------------------------------//
//容器：
//顺序：vector、deque、list
//关联：set、multiset、map、multimap
//适配：stack、queue、priority_queue
//---------------------------------------------//
//对象插入容器，存入的是拷贝
//放入容器的类，应该普遍重载< > == 
//---------------------------------------------//
//vector: <vector> 动态数组
//存取是常数，尾部插入常数(连续的存储空间足够)
//deque:<deque> 双向队列
//存取常数(大于vector),两端增删元素常数
//有头尾指针，增加删除元素通过移动指针完成
//存取的过程，通过head+bias的方式确定地址(连续存储空间)
//list<list>双向链表
//知道位置的前提下，增删元素是常数时间(修改两个指针，delete删除元素)
//不支持随机存取，只能遍历查找
//---------------------------------------------//
//关联容器：元素排序，查找时具有较好性能
//查找插入时间复杂度：O(logN)
//set/multiset <set>:集合
//set不允许有相同元素、multiset允许
//map/multimap <map>:只能存放对象，且对象的成员变量只能是两个
//一个为first 一个为second 对first 从小到达排序
//multimap 允许相同的first值
//---------------------------------------------// 
//stack <stack> :栈
//queue <queue> :队列
//priority_queue <queue> :优先队列
//---------------------------------------------// 
//顺序容器以及关联容器中的成员函数：
//begin         指向第一个元素的迭代器
//end           指向最后一个元素后一个位置的迭代器
//rbegin        指向最后一个元素的迭代器
//rend          指向第一个元素前一个位置的迭代器
//erase         删除一个或几个元素
//clear         清空容器
//---------------------------------------------//
//顺序容器常用成员函数：
//front             返回容器第一个的元素的引用
//back              返回容器最后一个元素的引用
//push_back         容器的末尾增加元素
//pop_back          容器的末尾删除元素
//erase             删除迭代器指向的元素或取间，返回删除元素后一个元素的迭代器


