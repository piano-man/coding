//activity selection
#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int start,finish;
}

int getactivities(int n,vector<int> start,vector<int> end)
{
    map<int,int> m;
    int i;
    int count = 1;
    for(i=0;i<n;i++)
    {
        m[end[i]] = start[i];
    }
    map<int,int>::iterator it;
    it = m.begin();
    int prev = it->first;
    it++;
    for(;it!=m.end();it++)
    {
        if(it->second>=prev)
        {
            cout << it->first << " ";
            count++;
            prev = it->first;
       }
        
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    int number[t];
    vector<vector<struct Activity> > activity;
    vector<vector<int> > start;
    vector<vector<int> > end;
    int i;
    for(i=0;i<t;i++)
    {
        activity.push_back(vector<struct Activity>());
        start.push_back(vector<int>());
        end.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int no;
        cin >> no;
        number[i] = no;
        int j;
        for(j=0;j<no;j++)
        {
            int n;
            cin >> n;
            start[i].push_back(n);
        }
        for(j=0;j<no;j++)
        {
            int n;
            cin >> n;
            end[i].push_back(n);
        }
        for(j=0;j<no;j++)
        {
            struct Activity a;
            a.start = start[i];
            a.finish = end[i];
            activity[i].push_back(a);
        }
    }
    for(i=0;i<t;i++)
    {
        cout << getactivities(number[i],activity[i]);
    }
}
