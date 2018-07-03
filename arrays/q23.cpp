//subset sum problem
//try with dynamic programming
#include<bits/stdc++.h>
using namespace std;

vector<int> converttoset(int n,vector<int> arr,int size)
{
    int j;
    vector<int> v;
    for(j=0;j<size;j++)
    {
        if((n & (1<<j))!=0)
        {
            v.push_back(arr[j]);
        }
    }
    return v;
}

set<vector<int> > getsubsets(vector<int> arr,int size)
{
    set<vector<int> >allsubsets;
    int max = pow(2,size);
    int i;
    for(i=0;i<max;i++)
    {
        vector<int> v = converttoset(i,arr,size);
        allsubsets.insert(v);
    }
    return allsubsets;
}

void divide(vector<int> v)
{
    int n = v.size();
    int i,j;
    int sum = 0;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
    }
    if(sum%2!=0)
    {
        cout << "NO";
        return;
    }
    set<vector<int> > result = getsubsets(v,n);
    set<vector<int> >::iterator it;
    for(it = result.begin();it!=result.end();it++)
    {
        int tsum = 0;
        vector<int> r = *it;
        j = r.size();
        int k;
        for(k=0;k<j;k++)
        {
            tsum+=r[k];
        }
        if(tsum==sum/2)
        {
            cout << "YES";
            return;
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