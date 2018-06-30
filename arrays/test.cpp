#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    deque<int> dq;
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    dq.push_back(10);
    dq.push_back(11);
    dq.push_back(12);
    cout << l.back() << "\n";
    cout << dq.front() << "\n";
}