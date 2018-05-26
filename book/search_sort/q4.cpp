//radix sort(sort numbers in linear time)
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void countSort(int arr,int n,int exp)
{
    
}

void rsort(int *arr,int n)
{
    countSort(arr,n,1);
    countSort(arr,n,n);
}

int main()
{
    int arr[] = {40, 12, 45, 32, 33, 1, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    rsort(arr,n);
}