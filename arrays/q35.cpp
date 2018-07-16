//Equilibrium point
#include<bits/stdc++.h>
using namespace std;

int point(vector<int> v,int n)
{
    int sum = 0;
    int currsum = 0;
    int i;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
    }
    for(i=0;i<n;i++)
    {
        currsum+=v[i];
        if(2*(currsum-v[i])+v[i] == sum)
        {
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
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
        cout << point(v,n);
        cout << "\n";
    }
}