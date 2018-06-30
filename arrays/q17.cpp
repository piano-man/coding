//inversion count
#include<bits/stdc++.h>
using namespace std;

int merge(int *arr,int *temp,int low,int mid,int high)
{
    int inv_count = 0;
    int i = low;
    int j = mid;
    int k = low;
    while(i<=mid-1&&j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            temp[k++] = arr[j];
            j++;
            inv_count+=mid-i;
        }
    }
    while(i<=mid-1)
    {
        temp[k++] = arr[i];
        i++;
    }
    while(j<=high)
    {
        temp[k++] = arr[j];
        j++;
    }
    return inv_count;
}

int mergeutil(int *arr,int *temp,int low,int high)
{
    int inv_count = 0;
    if(high>low)
    {
        int mid = (low+high)/2;
        inv_count = mergeutil(arr,temp,low,mid);
        inv_count+=mergeutil(arr,temp,mid+1,high);
        inv_count+=merge(arr,temp,low,mid+1,high);
    }
    return inv_count;

}

int mergeSort(int *arr,int n)
{
    int *temp = (int *)malloc(sizeof(int)*n);
    return mergeutil(arr,temp,0,n-1);
}

int main()
{
  int arr[] = {1, 20, 6, 4, 5};
  printf(" Number of inversions are %d \n", mergeSort(arr, 5));
}