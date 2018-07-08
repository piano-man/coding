//subset sum problem
//dynamic programming solution
#include<bits/stdc++.h>
using namespace std;

void divide(vector<int> v)
{
    int n = v.size();
    int i,j;
    int sum = 0;
    int table[n][n];
    memset(table,0,sizeof(table));
    for(i=0;i<n;i++)
    {
        sum+=v[i];
    }
    if(sum%2!=0)
    {
        cout << "NO";
        return;
    }
    for(i=0;i<n;i++)
    {
        table[i][i] = v[i];
        if(table[i][i]==sum/2)
        {
            cout << "YES";
            return;
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            table[i][j] = table[i][j-1]+v[j];
            if(table[i][j]==sum/2)
            {
                cout << "YES";
                break;
            }
        }
    }

}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<vector<int> >v;
    for(i=0;i<t;i++)
    {
        v.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int j;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v[i].push_back(k);
        }
    }
    for(i=0;i<t;i++)
    {
        divide(v[i]);
        cout << "\n";
    }
}