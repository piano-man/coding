//jumbled strings
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a;
	    cin>>a;
	    string b("GEEKS");
	    int l[6][n+1];
	    int i,j;
	    for(i=0;i<=5;i++)
	    {
	        for(j=0;j<=n;j++)
	        {
	            if(i==0)
	            l[i][j]=1;
	            else if(j==0)
	            l[i][j]=0;
	            else if(b[i-1]==a[j-1])
	            l[i][j]=l[i-1][j-1]+l[i][j-1];
	            else l[i][j]=l[i][j-1];
	        }
	    }
	    cout<<l[5][n]<<endl;
	 }
	return 0;
}