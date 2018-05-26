//smallest window containing all characters of another string
//doesn't work
#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;
    map<char,int> m;
    int l1 = s1.length();
    int l2 = s2.length();
    int i;
    for(i=0;i<l1;i++)
    {
        if(m[s1[i]]<i)
        {
            m[s1[i]]=i;
        }
        
    }
    for(i=0;i<l2;i++)
    {
        if(m[s2[i]]==0)
        {
            cout << -1 ;
            return 0;
        }
    }
    int start,end;
    start = m[s2[0]];
    end = m[s2[l2-1]];
    for(i=start;i<=end;i++)
    {
        cout << s1[i];
    }
}