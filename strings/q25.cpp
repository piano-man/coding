//string comparision
#include<bits/stdc++.h>
using namespace std;

int comparision(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int n = min(l1,l2);
    int i;
    for(i=0,j=0;i<n,j<n;i++)
    {

    }
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        cout << comparision(s1,s2);
    }
}