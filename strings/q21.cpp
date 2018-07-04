//implementing strstr
#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        cout<<strstr(a,b)<<endl;
    }
}

int getLCS(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int len = 0;
    int table[l1+1][l2+1];
    int i,j;
    int row,col;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                table[i][j]=1+table[i-1][j-1];
                if(len<table[i][j])
                {
                    len = table[i][j];
                    row = i;
                    col = j;
                }
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }
    if(len<l2)
    {
        return -1;
    }
    while(row!=0&&col!=0)
    {
        if(table[row][col]!=0)
        {
            row--;
            col--;
        }
        else
        {
            break;
        }
    }
    return row;
}

int strstr(string s, string x)
{
     int ans = getLCS(s,x);
     return ans;
}