//form a palindrome
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)
{   return a < b ? a : b;  }

int insertions(string s)
{
    int n = s.length();
    int table[n][n];
    int i;
    for(i=0;i<n;i++)
    {
        table[i][i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            table[i][i+1]=0;
        }
        else{
            table[i][i+1]=1;
        }
    }
    int sublen;
    for(sublen=3;sublen<=n;sublen++)
    {
        for(i=0;i<n-sublen+1;i++)
        {
            int j = i+sublen-1;
            if(s[i]==s[j])
            {
                table[i][j]=table[i+1][j-1];
            }
            else
            {
                table[i][j] = min(table[i+1][j],table[i][j-1])+1;
            }
        }
    }
    return table[0][n-1];
}

int main()
{
    string s = "geeks";
    int ans = insertions(s);
    cout << ans;
}