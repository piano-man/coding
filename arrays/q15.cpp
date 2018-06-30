//longest increasing subarray
#include<bits/stdc++.h>
using namespace std;

int longestsubarr(int *arr,int n)
{
    int i;
    int max_len = INT_MIN;
    int curr_len = 0;
    int start= 0;
    int end = 0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]>arr[i])
        {
            curr_len++;
            end++;
        }
        else
        {
            if(curr_len>max_len)
            {
                max_len = curr_len;
                start = i;
                curr_len = 1;
                end = i;
            }
        }
    }
    return max_len;
}

int main()
{
    int arr[] = {5, 6, 3, 5, 7, 8, 9, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length = "
         << longestsubarr(arr, n);
    return 0;     
}