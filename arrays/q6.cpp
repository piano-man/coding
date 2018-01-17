//kth smallest element(linear time)
//error
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include<algorithm>
using namespace std;

void swap(int* a,int* b)
{
    int t = *a;
    *a=*b;
    *b=t;
}
int partition(vector<int> v,int start,int end)
{
    int pivot;
    pivot = v[end];
    int i = start-1;
    int j;
    for(j=start;j<=end-1;j++)
    {
        if(v[j]<pivot)
        {
            i++;
            swap(&v[j],&v[i]);
        }
    }
    swap(&v[i+1],&v[end]);
    return (i+1);
}

int kthsmallest(vector<int> v , int start,int end,int k)
{
    if(k>0&&k<=end-start+1)
    {
        int pi = partition(v,start,end);
        if(pi-start==k-1)
        {
            cout << v[pi];
            return 0;
        }
        else if(pi-start>=k)
        {
            return kthsmallest(v,start,pi-1,k);
        }
        else
        {
            return kthsmallest(v,pi+1,end,k);
        }
    }

}

int main()
{
    vector<vector<int> >v;
    int size[200];
    int karr[200];
    int cases;
    cin >> cases;
    int i;
    for (i = 0; i < cases; i++)
    {
        v.push_back(vector<int>());
    }
    for(i=0;i<cases;i++)
    {
        cin >> size[i];
        int j;
        for(j=0;j<size[i];j++)
        {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
        cin >> karr[i];
    }
    for(i=0;i<cases;i++)
    {
        kthsmallest(v[i],0,size[i]-1,karr[i]);
    }

}