//longest common prefix(Divide and conquer)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string commonprefixUtil(string s1,string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    string result;
    int i,j;
    for(i=0,j=0;i<=n1-1,j<=n2-1;i++,j++)
    {
        if(s1[i]!=s2[j])
        {
            break;
        }
            result.push_back(s1[i]);
    }
    return result;

}

string commonprefix(string *arr,int low,int high)
{
    if(low==high)
    {
        return arr[low];
    }
    int mid = (high+low)/2;
    string s1 = commonprefix(arr,low,mid);
    string s2 = commonprefix(arr,mid+1,high);
    return (commonprefixUtil(s1,s2));
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks","geek", "geezer"};
    int n = sizeof(arr)/sizeof(arr[0]);
    string ans = commonprefix(arr,0,n-1);
    cout << ans;
}