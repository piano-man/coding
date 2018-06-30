//longest increasing sub sequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int *arr,int n)
{
    int i, j;
    int arr1[n];
    for(i=0;i<n;i++)
    {
        arr1[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&arr1[i]<arr1[j]+1)
            {
                arr1[i]=arr1[j]+1;
            }
        }
    }
    int max = INT_MIN;
    for(i=0;i<n;i++)
    {
        if(arr1[i]>=max)
        {
            max = arr1[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = lis(arr,n);
    cout << len;

}