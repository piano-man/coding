//Rearrange positive and negative numbers with constant extra space
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr,int l,int r)
{
    if(l<r)
    {
        swap(&arr[l],&arr[r]);
        l++;r--;
        reverse(arr,l,r);
    }
}

void merge(int *arr,int l,int m,int r)
{
    int lind = l;
    int rind = m+1;
    while(lind<=m&&arr[lind]<0)
    {
        lind++;
    }   
    while(rind<=r&&arr[rind]<0)
    {
        rind++;
    }
    reverse(arr,lind,m);
    reverse(arr,m+1,rind-1);
    reverse(arr,lind,rind-1);
}

void Rearrange(int *arr,int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        Rearrange(arr,l,m);
        Rearrange(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[] = {12, 11 ,-13 ,-5, 6, -7, 5 ,-3 ,-6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    Rearrange(arr, 0, arr_size - 1);
 
    int i;
    for(i=0;i<arr_size;i++)
    {
        cout << arr[i] << " ";
    }
 
    return 0;
}