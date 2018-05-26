//magic index(finds all magic indices)
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int magic(int *arr,int start,int end)
{
    if(end<start)
    {
        return -1;
    }
    int mid = (start+end)/2;
    int midval = arr[mid];
    if(mid==midval)
    {
        cout << mid << " ";
    }
    int leftindex = min(mid-1,midval);
    magic(arr,start,leftindex);
    int rightindex = max(mid+1,midval);
    magic(arr,rightindex,end);

}

int main()
{
    int arr[] = {-10,-5,2,2,2,3,4,5,9,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    magic(arr,0,n-1);
}