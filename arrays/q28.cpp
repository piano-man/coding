//Longest sub-sequence such that difference between adjacents is one 
//O(n^2)
#include<bits/stdc++.h>
using namespace std;

int longestsubsq(vector<int>v,int n)
{
    vector<int> arr(n,0);
    int i,j;
    int max = INT_MIN;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(abs(v[i]-v[j])==1)
            {
                arr[i] = max(arr[i],arr[j]+1);
                if(arr[i]>max)
                {
                    max = arr[i];
                }
            }
        }
    }
    return max+1;
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