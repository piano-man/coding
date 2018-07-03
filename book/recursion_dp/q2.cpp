//permutations of a set
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
void subset_gen(vector<int> v,int start,int end,unordered_map<int, int> m)
{
    if(start==end)
    {
        int i;
        for(i=0;i<end;i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    unordered_map<int, int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second!=0)
        {
            it->second = it->second-1;
            v.insert(v.begin()+start,it->first);
            subset_gen(v,start+1,end,m);
            it->second = it->second+1;
        }
    }

}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int i;
    for(i=0;i<n;i++)
    {
        int val;
        cin >> val;
        m[val]++;
    }
    //vector<vector<int> > sset;
    subset_gen(v,0,n,m);
}