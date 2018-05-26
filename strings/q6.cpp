//longest palindromic subsequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//int n;

// void printlcs(int n,int table[][n],string s)
// {
//     int len = table[0][n-1];
//     int i = 0;
//     int j = n-1;
//     char arr[n]={'0'};
//     while(len!=1)
//     {
//         if(s[i]==s[j])
//         {
//             arr[i] = s[i];
//             arr[j] = s[j];
//             i = i+1;
//             j = j-1;
//         }
//         else
//         {
//             if(table[i+1][j]>table[i][j-1])
//             {
//                 i = i+1;
//                 j = j;
//             }
//             else{
//                 i = i;
//                 j= j-1;
//             }
//         }
//         len = table[i][j];

//     }
//     for(i=0;i<n;i++)
//     {
//         if(arr[i]!='0')
//         {
//             cout << arr[i];
//         }
//     }
// }
int lps(string s)
{
    int n = s.length();
    int table[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        table[i][i]=1;
    }
    int sublen;
    for(sublen=2;sublen<=n;sublen++)
    {
        for(i=0;i<n-sublen+1;i++)
        {
            j = i+sublen-1;
            if(s[j]==s[i]&&sublen==2)
            {
                table[i][j]=2;
            }
            else if(s[j]==s[i])
            {
                table[i][j]=table[i+1][j-1]+2;
            }
            else if(s[j]!=s[i])
            {
                table[i][j]=max(table[i][j-1],table[i+1][j]);
            }
        }
    }
    //printlcs(n,table,s);

//printing the subsequence    
   int len = table[0][n-1];
    i = 0;
    j = n-1;
    char arr[n]={'0'};
    while(len!=1)
    {
        if(s[i]==s[j])
        {
            arr[i] = s[i];
            arr[j] = s[j];
            i = i+1;
            j = j-1;
        }
        else
        {
            if(table[i+1][j]>table[i][j-1])
            {
                i = i+1;
                j = j;
            }
            else{
                i = i;
                j= j-1;
            }
        }
        len = table[i][j];

    }
    for(i=0;i<n;i++)
    {
        if(arr[i]!='0')
        {
            cout << arr[i];
        }
    }

    
    return table[0][n-1];
}
int main()
{
    string s = "BBABCBCAB";
    //n = s.length();
    int ans = lps(s);
    cout << ans;
}