//longest substring with distinct characters
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int distinct(string s)
{
    int n = s.length();
    int curr_len=0,max_len=INT_MIN;
    int start = 0;
    int i;
    int *visited = (int *)malloc(256*sizeof(int));
    for(i=0;i<256;i++)
    {
        visited[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        if(visited[s[i]]==-1)
        {
            curr_len++;
            visited[s[i]]=i;
        }
        else if(visited[s[i]]!=-1&&visited[s[i]]<start)
        {
            curr_len++;
            visited[s[i]]=i;
        }
        else{
            if(curr_len>max_len)
            {
                max_len=curr_len;
            }
             visited[s[i]]=i;
             curr_len=1;
             start = i;
        }
    }
    return max_len;

}

int main()
{
    string s = "ABBCDEFGAAA";
    //string s = "geeksforgeeks"
    int ans = distinct(s);
    cout << ans;
}