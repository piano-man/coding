//cut segments
#include<bits/stdc++.h>

using namespace std;
#define pb push_back

int max(int n1,int n2,int n3)
{
    return max(max(n1,n2),n3);
}

int min(int n1,int n2,int n3)
{
    return min(min(n1,n2),n3);
}

int getmax(int length,vector<int> v,int *arr)
{
    if(length<0)
    {
        return INT_MIN;
    }
    if(length==0)
    {
        arr[length]=0;
        return 0;
    }
    if(length<min(v[0],v[1],v[2]))
    {
        return INT_MIN;
    }
    if(arr[length]!=0)
    {
        return arr[length];
    }
    arr[length] = 1+max(getmax(length-v[0],v,arr),getmax(length-v[1],v,arr),getmax(length-v[2],v,arr));
    return arr[length];
}
int main()
{
    int t;
    cin >> t;
    vector<int>v1;
    vector<vector<int> >v2;
    int i;
    for(i=0;i<t;i++)
    {
        v2.pb(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        v1.pb(n);
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        v2[i].pb(n1);
        v2[i].pb(n2);
        v2[i].pb(n3);
    }
    for(i=0;i<t;i++)
    {
        int arr[10000];
        memset(arr,0,sizeof(arr));
        int ans = getmax(v1[i],v2[i],arr);
        cout << ans << "\n";
    }
}