//largest sum contiguous subrray
#include<bits/stdc++.h>
using namespace std;

int largestsum(int arr[10000],int n)
{
    int curr_sum = 0,max_sum = INT_MIN,start,end;
    start=end=0;
    int i;
    for(i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum>=max_sum)
        {
            max_sum = curr_sum;
            end++;
        }
        else if(curr_sum>0)
        {
            continue;
        }
        else if(curr_sum<0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    int arr[10000];
    int n;
    cin >> n;
    int i;
    for(i=0;i<n;i++)
    {
        int num;
        cin >> num;
        arr[i]=num;
    }
    int ans = largestsum(arr,n);
    cout << ans;
}