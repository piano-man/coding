//sub sort
//O(n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findleftend(int *arr,int start,int end)
{
    int i;
    for(i=start+1;i<=end;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return i-1;
        }
    }
    return end;
}
int findrightstart(int *arr,int start,int end)
{
    int i;
    for(i=end;i>start;i--)
    {
        if(arr[i]<arr[i-1])
        {
            return i;
        }
    }
    return start;
}
int findmaximum(int *arr,int start,int end)
{
    int i,index;
    int max = INT_MIN;
    for(i=start;i<=end;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            index = i;

        }
    }
    return index;
}
int findminimum(int *arr,int start,int end)
{
    int i,index;
    int min = INT_MAX;
    for(i=start;i<=end;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}
int shrinkleft(int *arr,int start,int leftend,int minindex)
{
    int i,finalend;
    for(i=leftend;i>=start;i--)
    {
        if(arr[i]>arr[minindex])
        {
            finalend = i-1;
        }
    }
    return finalend;
}
int shrinkright(int *arr,int rightstart,int end,int maxindex)
{
    int i,finalend;
    for(i=rightstart;i<=end;i++)
    {
        if(arr[i]<arr[maxindex])
        {
            finalend = i+1;
        }
    }
    return finalend;
}

void findUnsorted(int *arr,int start,int end)
{
    int leftend = findleftend(arr,start,end);
    if(leftend==end)
    {
        return;
    }
    int rightstart = findrightstart(arr,start,end);
    int minindex = findminimum(arr,leftend+1,end);
    int maxindex = findmaximum(arr,start,rightstart-1);
    int leftindex = shrinkleft(arr,start,leftend,minindex);
    int rightindex = shrinkright(arr,rightstart,end,maxindex);
    cout << leftindex+1 << " " << rightindex-1;
}
int main()
{
    int arr[] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    findUnsorted(arr,0,n-1);
}