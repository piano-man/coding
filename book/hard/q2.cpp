//k smallest elements in an array
//ask someone
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

vector<int> findksmallest(int *arr,int low,int high,int k,vector<int> &result)
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
            for(i=low;i<=midstart;i++)
            {
                result.push_back(arr[i]);
            }
            return result;
        }
        else if(midstart-low<k-1)
        {
            for(i=low;i<=midstart;i++)
            {
                result.push_back(arr[i]);
            }
            return findksmallest(arr,midend+1,high,k-midstart+1,result);
        }
        else if(midstart-low>k-1)
        {
            return findksmallest(arr,low,midstart-1,k,result);
        }
    }
}

int main()
{
    int arr[] = {1,2,4,4,6,6,9,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> result;
    int k;
    cin >> k;
    vector<int> rel = findksmallest(arr,0,n-1,k,result);
    int i;
    for(i=0;i<k;i++)
    {
        cout << rel[i] << " ";
    }
}