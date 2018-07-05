//transform the array
//can't find error
#include<bits/stdc++.h>
using namespace std;

vector<int> transform(vector<int> v,int n)
{
    int i;
    for(i=0;i<n-1;)
    {
        int n1 = v[i];
        int j = i+1;
        while(v[j]==0)
        {
            j++;
        }
        int n2 = v[j];
        if(n1==n2)
        {
            v[i] = 2*v[i];
            v[j] = 0;
            i=i;
        }
        else
        {
            i=j;
        }
    }
    vector<int> result;
    int count = 0;
    for(i=0;i<n;i++)
    {
        if(v[i]!=0)
        {
            result.push_back(v[i]);
            count++;
        }
    }
    i = count;
    for(i=count;i<n;count++)
    {
        result.push_back(0);
    }
    return result;
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
        int j;
        vector<int> v;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        vector<int> ans = transform(v,n);
        for(j=0;j<n;j++)
        {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
}


