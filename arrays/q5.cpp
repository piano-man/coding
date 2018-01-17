//sort by frequency
//run with -std=c++0x flag added to g++ command
#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int,int>&p1,pair<int,int>&p2)
{
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }
    return p1.second>p2.second;

}
int main()
{
    int cases;
    int arr[200];
    cin >> cases;
    int i;
    vector<vector<int> > v;
    for (i = 0; i < cases; i++)
    {
        v.push_back(vector<int>());
    }
    //int *array[cases];
    for (i = 0; i < cases; i++)
    {
        cin >> arr[i];
        int j;
        for (j = 0; j < arr[i]; j++)
        {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
    }
    for(i=0;i<cases;i++)
    {
        map<int,int> m;
        int j = arr[i];
        int l;
        for(l=0;l<j;l++)
        {
            m[(v[i][l])]++;
        }
        int s = m.size();
        pair<int,int> p[s];
        for(auto it =m.begin();it!=m.end();it++)
        {
            p[i++]=make_pair(it->first,it->second);
        }
        sort(p,p+s,compare);
        for(l=0;l<s;l++)
        {
            int times = p[l].second;
            while(times--)
            {
                cout << p[l].first ;
            }
        }
        cout << endl;
    }
}