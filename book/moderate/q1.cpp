//smallest difference pair in arrays
#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int calc_diff(map<int,string> m1)
{
    int mindiff=10000;
    int currdiff;
    int count = 0;
    string s1 = m1.begin()->second;
    int val = m1.begin()->first;
    int len = m1.size();
    map<int,string>::iterator it;
    it=m1.begin();
    it++;
    for(;it!=m1.end();it++)
    {
        if(it->second.compare(s1)==0)
        {
            count++;
            val = it->first;
        }
        else
        {
            currdiff = it->first - val;
            if(currdiff<mindiff)
            {
                mindiff=currdiff;
            }
            s1 = it->second;
            val = it->first;
        }
    }
    return mindiff;
}

int main()
{
    map<int,string> m1;
    vector<int> v1,v2;
    int i,l1,l2;
    cin >> l1;
    cin >> l2;
    for(i=0;i<l1;i++)
    {
        int n1;
        cin >> n1;
        v1.push_back(n1);
        m1[n1]="a1";
    }
    for(i=0;i<l2;i++)
    {
        int n2;
        cin >> n2;
        v2.push_back(n2);
        m1[n2]="a2";
    }

    int min_diff = calc_diff(m1);
    cout << min_diff;
}