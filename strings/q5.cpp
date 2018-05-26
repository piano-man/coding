//longest common subsequence
#include<bits/stdc++.h>

using namespace std;

int max(int n1,int n2)
{
    if(n1>=n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int lcs(string s1,string s2,int l1,int l2)
{
    int table[l1+1][l2+1];
    int i,j;
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
                table[i][j]=table[i-1][j-1] + 1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);                
            }
        }
    }
    return table[l1][l2];
}

int main()
{
    int l1,l2;
    string s1,s2;
    cin >> l1;
    cin >> l2;
    cin >> s1;
    cin >> s2;
    int sublen = lcs(s1,s2,l1,l2);
    cout << sublen;
}