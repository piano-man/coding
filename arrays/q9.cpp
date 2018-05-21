//maximum sum increasing sub sequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int *arr,int n)
{
    int i, j;
    int arr1[n];
    int sum[n];
    for(i=0;i<n;i++)
    {
        arr1[i]=1;
    }
    for(i=0;i<n;i++)
    {
        sum[i]=arr[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {   
                sum[i]=sum[j]+arr[i];
                arr1[i]=arr1[j]+1;
            }
        }
    }
    int max = INT_MIN;
    for(i=0;i<n;i++)
    {
        if(sum[i]>=max)
        {
            max = sum[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {1,101,2,3,100,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = lis(arr,n);
    cout << len;

}