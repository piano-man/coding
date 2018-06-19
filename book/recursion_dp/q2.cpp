//subsets of a set(doubt)
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

map<int,int> m;
subset_gen(vector<int> set,int start,int end)
{
    if(start==end)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    int count = 0;
    while(count<=end)
    {
        
    }

}
int main()
{
    vector<int> set;
    int n;
    cin >> n;
    int i;
    for(i=0;i<n;i++)
    {
        int val;
        cin >> val;
        m[val]++;
        set.push_back(val);
    }
    //vector<vector<int> > sset;
    subset_gen(set,0,n);
}