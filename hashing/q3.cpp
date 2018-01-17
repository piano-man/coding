//array sum divisibility
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int check(int arr[],int k)
{
    unordered_map<int,int> freq;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(n%2!=0)
    {
        return false;
    }
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            freq[arr[i]%k]++;
            
        }
        

    }
}
int main()
{
    int arr[] = {9,7,5,3};
    int k = 6;
    cout << check(arr,k);
}