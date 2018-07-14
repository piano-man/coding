//Reorganize The Array 
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reorganise(vector<int> v,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i]!=i&&v[i]!=-1)
        {
            swap(&v[i],&v[v[i]]);
            i--;
        }
    }
    for(i=0;i<n;i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int j;
        vector<int> v;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        reorganise(v,n);
        cout << "\n";
    }
}