//kadane's algorithm
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxsum(int *arr,int n)
{
    int curr_max = arr[0];
    int max_so_far = arr[0];
    int i;
    int start = 0, end = 0,fs = 0,fe = 0;
    for(i=1;i<n;i++)
    {
        //curr_max = max(arr[i],curr_max+arr[i]);
        //max_so_far = max(max_so_far,curr_max);
        if(curr_max+arr[i]>=arr[i])
        {
            curr_max = curr_max + arr[i];
            end = i;
        }
        else if(arr[i]>curr_max+arr[i])
        {
            start = i;
            end = i;
            curr_max = arr[i];
        }
        if(curr_max>=max_so_far)
        {
            fs = start;
            fe = end;
            max_so_far = curr_max;
        }


    }
    cout << max_so_far << fs << fe ;
    
}

int main()
{
    int arr[] = {-2, -3, -4, -1, -2, -10, -5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = maxsum(arr,n);
}