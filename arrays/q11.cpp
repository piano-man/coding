//maximum of all sub-arrays of size k
#include <iostream>
#include <deque>
 
using namespace std;
 
void printmax(int *arr,int n,int k)
{
    deque<int> dq;
    int i;
    for(i=0;i<k;i++)
    {
        while(!dq.empty()&&arr[i]>arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<n;i++)
    {
        cout << arr[dq.front()] << " ";
        while(!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty()&&arr[i]>arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printmax(arr, n, k);
    return 0;
}