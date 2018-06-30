//coin piles
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int i;
    int arr[2005];
    for(i=0;i<t;i++)
    {
        cin >> n >> k;
        int j;
        int sums[n];
        int 
        memset(sums,0,sizeof(sums));
        for(j=0;j<n;j++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            if(i>0)
            {
                sums[i] = arr[i]+sums[i-1];
            }
            else
            {
                sums[i] = arr[i];
            }
        }
        for(i=0;i<n;i++)
        {
            int ind = upper_bound(arr,arr+n,arr[i]+k);

        }
        
    }
}