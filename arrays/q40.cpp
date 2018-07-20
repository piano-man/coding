//count the triplets
#include<bits/stdc++.h>
using namespace std;

int getcount(vector<int> v,int n)
{
    map<int,int> m;
    int i;
    for(i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    int j;
    int count = 0;
    for(i=0;i<n;i++)
    {
        int j = i+1;
        while(j<=n-1)
        {
            int ele = v[i]+v[j];
            if(m.find(ele)!=m.end())
            {
                count++;
            }
            j++;
        }
    }
    if(count==0)
    {
        return -1;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        vector<int> v;
        int i;
        for(i=0;i<n;i++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        cout << getcount(v,n);
        cout << "\n";
    }
}