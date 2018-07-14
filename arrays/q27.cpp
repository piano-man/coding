//subset sum problem
//dynamic programming solution
//subset sum problem
//dynamic programming solution
#include<bits/stdc++.h>
using namespace std;

void divide(vector<int> v,int n)
{
    int sum = 0;
    int  i,j;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
    }
    if(sum%2!=0)
    {
        cout << "NO";
        return;
    }
    sum = sum/2;
    bool table[n+1][sum+1];
    for(i=0;i<=n;i++)
    {
        table[i][0]=true;
    }
    for(i=0;i<=sum;i++)
    {
        table[0][i]=false;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<v[i-1])
            {
                table[i][j] = table[i-1][j];    
            }
            else if(j>=v[i-1])
            {
                table[i][j] = table[i-1][j] || table[i-1][j-v[i-1]];
            }
            
        }
    }
    if(table[n][sum]==true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        vector<int> v;
        int j;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        divide(v,n);
        cout << "\n";
    }

}