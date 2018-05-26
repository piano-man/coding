//group anagrams
//can use a hash map instead of sorting
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


bool comp_ana(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    //cout << s1 << "\n";
    sort(s2.begin(),s2.end());
    if(s1.compare(s2)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    vector<string> v1;
    int i,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        string s1;
        cin >> s1;
        v1.push_back(s1);
    }
    sort(v1.begin(),v1.end(),comp_ana);
    for(auto j:v1)
    {
        cout << j << "\n";
    }

}

