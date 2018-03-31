//largest contiguous sum
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int contiguous(vector<int> v,int size)
{
    int running_sum  = 0;
    int max_sum = -1000;
    int start_pos = 0;
    int end_pos;
    int i;
    for(i=0;i<size;i++)
    {
        running_sum+=v[i];
        if(running_sum>max_sum)
        {
            max_sum = running_sum;
            end_pos = i;
        }
        if(running_sum<0)
        {
            start_pos = i+1;
            end_pos = start_pos;
            running_sum = 0;
        }
    }
    return max_sum;
    
}

int main()
{
    vector<int> v;
    int l,i;
    cin >>  l;
    for(i=0;i<l;i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }
    int sum = contiguous(v,l);
    cout << sum;
}