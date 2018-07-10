//subsets of a set
#include<bits/stdc++.h>
using namespace std;

vector<int> converttoset(int n,int *arr,int size)
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

set<vector<int> > getsubsets(int *arr,int size)
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

int main()
{
    int arr[] = { 10, 12, 12 };
    int n = sizeof(arr)/sizeof(arr[0]);
    set<vector<int> > result = getsubsets(arr,n);
    int l = result.size();
    int i,j;
    set<vector<int> >::iterator it;
    for(it = result.begin();it!=result.end();it++)
    {
        vector<int> r = *it;
        j = r.size();
        int k;
        for(k=0;k<j;k++)
        {
            cout << r[k] << " ";
        }
        cout << "\n";
    }
}