//quicksort
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int *arr,int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi,high);
    }


}
int main()
{
    int arr[] = {1,4,2,7,8,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    int i;
    for(i=0;i<n;i++)
    {
        cout << arr[i];
    }
}