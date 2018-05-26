//permutations of a string with duplicates
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int c[26];

void permute(string s,int start,int end)
{
    if(start==end)
    {
        s[start] = '\0';
        cout << s << "\n";
    }
    int i;
    for(i=0;i<26;i++)
    {
        if(c[i])
        {
            c[i]--;
            s[start] = (char)(i+'a');
            permute(s,start+1,end);
            c[i]++;
        }
    }
}
int main()
{
    string s ="hello";
    int n = s.length();
    int i;
    for(i=0;i<n;i++)
    {
        c[s[i]-'a']++;
    }
    permute(s,0,n);
}