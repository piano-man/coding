//minimum number of swaps
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}
int minSwaps(int A[], int N){
	pair<int,int> p[N];
	int i;
	for(i=0;i<N;i++)
	{
		p[i].first = A[i];
		p[i].second = i;
	}
	sort(p,p+N);
	int count = 0;
	vector<bool> vis(N,false);
	for(i=0;i<N;i++)
	{
		if(vis[i]||p[i].second==i)
		{
			continue;
		}
		int j = i;
		int cycle = 0;
		while(!vis[j])
		{
			vis[j]= true;
			j = p[j].second;
			cycle++;
		}
		count+=cycle-1;
	}
	return count;
}