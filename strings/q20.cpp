//interleaved strings
//dynamic programming method
#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}

bool isInterleave(string A, string B, string C) 
{
    int l1 = A.length();
    int l2 = B.length();
    int l3 = C.length();
    int table[l1+1][l2+1];
    memset(table,0,sizeof(table));
    if(l1+l2!=l3)
    {
        return 0;
    }
    int i,j;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0&&j==0)
            {
                table[i][j]=1;
            }
            else if(i==0&&B[j-1]==C[j-1])
            {
                table[i][j]=table[i][j-1];
            }
            else if(j==0&&A[i-1]==C[i-1])
            {
                table[i][j]=table[i-1][j];
            }
            else if(A[i-1]==C[i+j-1]&&B[j-1]!=C[i+j-1])
            {
                table[i][j]=table[i-1][j];
            }
            else if(A[i-1]!=C[i+j-1]&&B[j-1]==C[i+j-1])
            {
                table[i][j] = table[i][j-1];
            }
            else if(A[i-1]==C[i+j-1]&&B[j-1]==C[i+j-1])
            {
                table[i][j] = (table[i-1][j] || table[i][j-1]);
            }
        }
    }
    return table[l1][l2];
}