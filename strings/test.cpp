#include<bits/stdc++.h>
using namespace std;

string rollingString(char *s,int n,char **arr)
{
    int i;
    for(i=0;i<n;i++)
    {
        int l = 5;
        int j;
        char start,end,ch;
        int s,e;
        start = arr[i][0];
        s = start - '0';
        end = arr[i][2];
        e = end - '0';
        ch = arr[i][4];
        for(j=s;j<=e;j++)
        {
            if(ch=='R')
            {
                if(s[j]=='z')
                {
                    s[j]=a;
                }
                else
                {
                    s[j]+=1;
                }
            }
            if(ch=='L')
            {
                if(s[j]=='a')
                {
                    s[j]='z';
                }
                else
                {
                    s[j]-=1;
                }
            }
        }
    }
    return s;
}