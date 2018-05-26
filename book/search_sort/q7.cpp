//sub sort
//O(nlogn)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subsort(int *arr,int start,int end)
{
    vector<int> v (end+1);
    copy ( arr, arr+(end+1), v.begin() );
    sort(arr,arr+(end+1));
    int fdiff,ldiff=INT_MIN,min;
    int flag=0;
    int i;
    for(i=0;i<=end;i++)
    {
        if((v[i]!=arr[i])&&flag==0)
        {
            fdiff = i;
            flag=1;
        }
        if((v[i]!=arr[i])&&flag==1)
        {
            min = i;
            if(min>ldiff)
            {
                ldiff = min;
            }
        }
    }
    cout << fdiff << " " << ldiff;
}

int main()
{
    int arr[] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    subsort(arr,0,n-1);
}