//search in rotated array
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int find(int *arr, int start, int end, int s)
{
    if (start <= end)
    {

        int mid = (start + end) / 2;
        int e1 = arr[start];
        int e2 = arr[mid];
        if(s==e1)
        {
            return start;
        }
        if(s==e2)
        {
            return mid;
        }
        if (s > e1 && e2 <= e1)
        {
            return find(arr,start+1,mid,s);
        }
        if(s<e1&&e2>=e1)
        {
            return find(arr,mid+1,end,s);
        }
        if(s>e1&&e2>=e1)
        {
            if(s<e2)
            {
                return find(arr,start+1,mid,s);
            }
            if(s>e2)
            {
                return find(arr,mid+1,end,s);
            }

        }
        if(s<e1&&e2<=e1)
        {
            if(s>e2)
            {
                return find(arr,mid+1,end,s);
            }
            if(s<e2)
            {
                return find(arr,start+1,mid-1,s);
            }
        }
    }
}

int main()
{
    int arr[] = { 15,
                  20,
                  25,
                  30,
                  1,
                  4,
                  10,
                  12,
                  13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int s;
    cin >> s;
    int i = find(arr, 0, n - 1, s);
    cout << i;
}