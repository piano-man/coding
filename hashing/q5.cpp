//pairs with given sum
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<array>

using namespace std;

int main()
{
    int arr1[] = {-1, -2, 4, -6, 5, 7};
    int arr2[] = {6, 3, 4, 0};
    int x;
    cin >> x;
    unordered_map<int,int> hm1;
    unordered_map<int,int> hm2;
    int l1 = sizeof(arr1)/sizeof(int);
    int l2 = sizeof(arr2)/sizeof(int);
    int i;
    for(i=0;i<l1;i++)
    {
        hm1[arr1[i]]=1;
    }
    for(i=0;i<l2;i++)
    {
        int ans = x-arr2[i];
        if(hm1[ans]!=0)
        {
            cout << ans << " " << arr2[i] << "," ;
        }
    }
}