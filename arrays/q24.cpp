//triplets with zero sum
//O(1) space
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int arr[n]={0};
	for(int i=0;i<n;i++)
		cin>>arr[i];
    if(findTriplets(arr, n))
    cout<<"1"<<endl;
    else 
    cout<<"0"<<endl;
	}
    return 0;
}
bool findTriplets(int arr[], int n)
{ 
    int i,j,k;
    sort(arr,arr+n);
    for(i=0;i<n-1;i++)
    {
        int sum = 0;
        j = i+1;
        k = n-1;
        while(j<k)
        {
            sum = arr[i]+arr[j]+arr[k];
            if(sum==0)
            {
                return true;
            }
            if(sum<0)
            {
                j++;
            }
            if(sum>0)
            {
                k--;
            }
        }
    }
    return false;
}