//masseuse
#include<bits/stdc++.h>
using namespace std;

int maxsum(int *arr,int index,int n,int *rel)
{
    if(index>=n)
    {
        return 0;
    }
    if(rel[index]==0)
    {
    int maxwith = arr[index]+maxsum(arr,index+2,n,rel);
    int maxwithout = maxsum(arr,index+1,n,rel);
    rel[index] = max(maxwith,maxwithout);
    }
    return rel[index];

}

int main()
{
    int arr[] = {30,15,60,75,45,15,15,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    int rel[n];
    memset(rel,0,sizeof(rel));
    cout << rel[4] << "\n";
    int ans = maxsum(arr,0,n,rel);
    cout << ans;
}