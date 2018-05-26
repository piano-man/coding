//subsets of a set(doubt)
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

subset_gen(vector<vector<int> > &sset,vector<int> set)
{

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
        set.push_back(val);
    }
    vector<vector<int> > sset;
    subset_gen(sset,set);
}