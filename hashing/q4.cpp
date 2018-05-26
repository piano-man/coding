//distinct elements in every window
//O(N)
#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

void countDistinct(vector<int> v,int k,int n)
{
    unordered_map<int,int> hm;
    int dist_count = 0;
    int i;
    for(i=0;i<k;i++)
    {
        if(hm[v[i]]==0)
        {
            dist_count++;

        }
        hm[v[i]]++;
        
    }
    cout << dist_count << " ";
    for(i=k;i<n;i++)
    {
        if(hm[v[i-k]]==1)
        {
            dist_count--;
        }
        hm[v[i-k]]--;
        if(hm[v[i]]==0)
        {
            dist_count++;
        }
        hm[v[i]]++;
        cout << dist_count << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<int> s;
    vector<int> ws;
    vector<vector<int> >v;
    for(i=0;i<t;i++)
    {
        v.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int a,k;
        cin >> a;
        cin >> k;
        s.push_back(a);
        ws.push_back(k);
        int j;
        for(j=0;j<a;j++)
        {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
    }
    for(i=0;i<t;i++)
    {
        countDistinct(v[i],ws[i],s[i]);
    }
}