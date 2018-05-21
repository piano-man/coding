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

int quicksort(int *arr,int low,int high,int k)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        if(pi==k-1)
        {
            return arr[pi];
        }
        if(pi>k-1)
        {
        return quicksort(arr,low,pi-1,k);
        }
        return quicksort(arr,pi,high,k);


    }

return INT_MAX;
}
int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    int ans = quicksort(arr,0,n-1,k);
    cout << ans;
}