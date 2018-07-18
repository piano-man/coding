//maximum product subaray
#include<bits/stdc++.h>
using namespace std;

int product(vector<int> v,int n)
{
    int currmax = 1;
    int currmin = 1;
    int finalmax = INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i]>0)
        {
            currmax = currmax*v[i];
            currmin = min(currmin*v[i],1);
        }
        else if(v[i]==0)
        {
            currmax = 1;
            currmin = 1;
        }
        else if(v[i]<0)
        {
            int temp = currmax;
            currmax = max(1,currmin*v[i]);
            currmin = temp*v[i];
        }
        if(currmax>finalmax)
        {
            finalmax = currmax;
        }
    }
    return finalmax;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int i;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        cout << product(v,n);
        cout << "\n";
    }
}