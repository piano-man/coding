//maximum sum incresing subsequence
#include<bits/stdc++.h>
using namespace std;

int lis(int *arr,int n)
{
    int max_sum = INT_MIN;
    int sum[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        sum[i] = arr[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&sum[j]+arr[i]>sum[i])
            {
                sum[i] = sum[j]+arr[i];
                if(sum[i]>max_sum)
                {
                    max_sum = sum[i];
                }
            }
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {1,101,2,3,100,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = lis(arr,n);
    cout << len;
}