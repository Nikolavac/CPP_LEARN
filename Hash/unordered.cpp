#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    unordered_map<string,int>turing_Winner;
    turing_Winner.insert(make_pair("Dijkstra",1972));
    turing_Winner.insert(make_pair("Scott",1976));
    turing_Winner.insert(make_pair("Wilkes",1967));
    turing_Winner.insert(make_pair("Hamming",1968));

    turing_Winner["Ritchie"] = 1983;
    string name;
    cin >> name;

    unordered_map<string,int>::iterator p = turing_Winner.find(name);
    if(p != turing_Winner.end())
        cout << p->second;
    else    
        cout << "Not Found" << endl;

    system("pause");
    return 0;
}
