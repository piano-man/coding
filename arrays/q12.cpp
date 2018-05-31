//kth number of 2 sorted arrays
//doubt in divide and conquer approach
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findkth(int *arr1,int *arr2,int l1,int l2,int k)
{
    int i = 0,j = 0,count = 0;
    int arr[l1+l2];
    while(i<l1&&j<l2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[count] = arr1[i];
            i++;
            count++;
        }
        else{
            arr[count] = arr2[j];
            j++;
            count++;
        }
    }
    while(i<l1)
    {
        arr[count] = arr1[i];
        i++;
        count++;
    }
    while(j<l2)
    {
        arr[count] = arr2[j];
        j++;
        count++;
    }
    return arr[k-1];
}

int main()
{
    int arr1[] = {1,3,7,8,13};
    int arr2[] = {5,9,13,15,21};
    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);
    int k = 6;
    int ans = findkth(arr1,arr2,l1,l2,k);
    cout << ans;
}