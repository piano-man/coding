//longest consecutive subsequence
#include<bits/stdc++.h>
using namespace std;

int longestsubsq(vector<int> v,int n)
{
    vector<int> arr(n,1);
    int i,j;
    int m = 1;
    sort(v.begin(),v.end());
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(v[i]-v[j]==1)
            {
                arr[i] = max(arr[i],arr[j]+1);
                if(arr[i]>m)
                {
                    m = arr[i];
                }
            }
        }
    }
    return m;
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
        cout << longestsubsq(v,n);
        cout << "\n";
    }
}