//merge sort
//can't find error
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int *arr,int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r - mid;
    int t1[n1];
    int t2[n2];
    int j;
    for(j=0;j<n1;j++)
    {
        t1[j]=arr[j+l];
    }
    for(j=0;j<r;j++)
    {
        t2[j]=arr[j+mid+1];
    }
    int k = l;
    int i = 0;
    j = 0;
    while(i<n1&&j<n2)
    {
        if(t1[i]<=t2[j])
        {
            arr[k]=t1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=t2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=t1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=t2[j];
        k++;
        j++;

    }

}

void mergesort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main()
{
    int arr[] = {1,4,2,7,8,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);    
    int i;
    for(i=0;i<n;i++)
    {
        cout << arr[i];
    }
}