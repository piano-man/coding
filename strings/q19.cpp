//edit distance(dynamic programming)
#include<bits/stdc++.h>
using namespace std;

int min(int n1,int n2,int n3)
{
    return min(min(n1,n2),n3);
}

int getmin(int m,int n,string s1,string s2)
{
    int table[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
            {
                table[i][j]=j;
            }
            else if(j==0)
            {
                table[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1])
            {
                table[i][j] = table[i-1][j-1];
            }
            else
            {
                table[i][j] = 1+min(table[i][j-1],table[i-1][j],table[i-1][j-1]);
            }
        }
    }
    return table[m][n];
}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<vector<int> >v1;
    vector<vector<string> >v2;
    for(i=0;i<t;i++)
    {
        v1.push_back(vector<int>());
        v2.push_back(vector<string>());
    }
    for(i=0;i<t;i++)
    {
        int n1;
        int n2;
        cin >> n1 >> n2;
        v1[i].push_back(n1);
        v1[i].push_back(n2);
        string s1,s2;
        cin >> s1 >> s2;
        v2[i].push_back(s1);
        v2[i].push_back(s2);
    }
    for(i=0;i<t;i++)
    {
        int ans = getmin(v1[i][0],v1[i][1],v2[i][0],v2[i][1]);
        cout << v1[i][0] << " " << v2[i][0] << "\n";
        cout << v1[i][1] << " " << v2[i][1] << "\n";
        cout << ans << "\n";
    }

}