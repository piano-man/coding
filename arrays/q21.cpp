//minimum number of jumps
//dynamic programming approach
#include<bits/stdc++.h>
using namespace std;

int minJumps(int *arr,int n)
{
    int jumps[n];
    if(n==0||arr[0]==0)
    {
        return -1;
    }
    jumps[0] = 0;
    int i,j;
    for(i=1;i<n;i++)
    {
        jumps[i] = INT_MAX;
        for(j=0;j<i;j++)
        {
            if(i<=j+arr[j]&&jumps[j]!=INT_MAX)
            {
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[n-1];
}

int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}