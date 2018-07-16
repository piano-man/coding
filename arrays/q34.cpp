//Sort an array of 0s, 1s and 2
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortvector(vector<int> &v,int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high)
    {
        if(v[mid] == 0)
        {
            swap(&v[low],&v[mid]);
            low++;
            mid++;
            continue;
        }
        else if(v[mid]==2)
        {
            swap(&v[mid],&v[high]);
            high--;
            continue;
        }
        mid++;
    }
    int i;
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
        sortvector(v,n);
        cout << "\n";
    }
}