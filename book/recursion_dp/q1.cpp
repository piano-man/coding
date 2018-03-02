//no. of ways to climb a staircase
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int steps=0;
int steps_ways(int n,map<int,int> v)
{
    if(n<0)
    {
        return 0;
    }
    else if(n==0)
    {
        return 1;
    }
    else if(v[n]!=0)
    {
        return v[n];
    }
    else
    {
        v[n]=steps_ways(n-1,v)+steps_ways(n-2,v)+steps_ways(n-3,v);
        return v[n];
    }
}
int main()
{
    map<int,int> v;
    int n;
    cin >> n;
    cout << steps_ways(n,v);
}