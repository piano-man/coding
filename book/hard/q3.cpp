//quick select with non-distinct elements
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low;j<=high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int findkthsmallest(int *arr,int low,int high,int k)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        int i,flag=0,midstart,midend;
        midend = midstart = pi;
        while(midstart>low)
        {
            if(arr[midstart-1]==arr[midstart])
            {
                midstart--;
            }
            else
            {
                break;
            }
        }
        if(midstart-low==k-1)
        {
            return arr[midstart];
        }
        else if(midstart-low<k-1)
        {
            return findkthsmallest(arr,midend+1,high,k-midstart+1);
        }
        else if(midstart-low>k-1)
        {
            return findkthsmallest(arr,low,midstart-1,k);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,4,4,6,6,9,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    int ans = findkthsmallest(arr,0,n-1,k);
    cout << ans;
}