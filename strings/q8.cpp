//longest palindromic substring
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lps(string s)
{
    int n = s.length();
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int i,j;
    int maxlength = 1;
    for(i=0;i<n;i++)
    {
        table[i][i]=true;
    }
    int sublen;
    for (i = 0; i < n-1; ++i)
    {
        if (s[i] == s[i+1])
        {
            table[i][i+1] = true;
            maxlength = 2;
        }
    }
    for(sublen=3;sublen<=n;sublen++)
    {
        for(i=0;i<n-sublen+1;i++)
        {
            j=i+sublen-1;
            if(s[i]==s[j])
            {
                if(table[i+1][j-1])
                {
                    table[i][j]=true;
                    if(sublen>maxlength)
                    {
                        maxlength = sublen;
                    }
                }
                
            }
        }
    }
    return maxlength;
}

int main()
{
    string s = "BBABCBCAB";
    int ans = lps(s);
    cout << ans;
}