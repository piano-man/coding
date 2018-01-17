//subarray with 0 sum
//compile with g++ -std=c++0x q1.cpp
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int maxlength(int arr[],int n)
{
    unordered_map<int,int> subsum;
    int sum = 0;
    int maxlen = 0;
    int i;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(arr[i]==0 && maxlen == 0)
        {
            maxlen = 1;
        }
        if(sum==0)
        {
            maxlen = i+1;

        }
        if(subsum.find(sum)!=subsum.end())
        {
            maxlen = max(maxlen,i-subsum[sum]);
        }
        else
        {
            subsum[sum]=i;
        }
    }
    return maxlen;
}
int main()
{
    int arr[]={15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = maxlength(arr,n);
    cout << len;
}