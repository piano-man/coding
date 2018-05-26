//longest substring with k unique chracters
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(int *count,int k)
{
    int unq = 0;
    int i;
    for(i=0;i<256;i++)
    {
        if(count[i]>0)
        {
            unq++;
        }
    }
    return (k>=unq);
}

int kunique(string s,int k)
{
    int n = s.length();
    int *count = (int *)malloc(256*sizeof(int));
    int i;
    int max_length = INT_MIN;
    for(i=0;i<n;i++)
    {
        count[i]=0;
    }
    int unique=0;
    int curr_start = 0,curr_end = 0;
    count[s[0]] = 1;
    unique++;
    for(i=1;i<n;i++)
    {
        
        count[s[i]]++;
        curr_end++;
        while(!isValid(count,k))
        {
            count[s[curr_start]]--;
            curr_start++;
        }
        if(curr_end-curr_start+1>max_length)
        {
            max_length = curr_end-curr_start+1;
        }
        
    }
    return max_length;

}

int main()
{
    string s = "aabacbebebe";
    int k;
    cin >> k;
    int len = kunique(s,k);
    cout << len;
}