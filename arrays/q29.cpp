//Longest sub-sequence such that difference between adjacents is one 
//O(n)
#include<bits/stdc++.h>
using namespace std;

int longestsubsq(vector<int>arr,int n)
{
    unordered_map<int,int> m;
    int i;
    int maxval = INT_MIN;
    for(i=0;i<n;i++)
    {
        int tmax = INT_MIN;
        if(m.find(arr[i]-1)!=m.end())
        {
            tmax = max(m[arr[i]-1],tmax);
        }
        if(m.find(arr[i]+1)!=m.end())
        {
            tmax = max(m[arr[i]+1],tmax);
        }
        if(tmax!=INT_MIN)
        {
            m[arr[i]] = tmax+1;
        }
        else
        {
            m[arr[i]] = 1;
        }
        if(m[arr[i]]>maxval)
        {
            maxval = m[arr[i]];
        }
    }
    return maxval;
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
        cout << longestsubsq(v,n);
        cout << "\n";
    }
}