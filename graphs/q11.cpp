//strongly connected components
#include<bits/stdc++.h> 
using namespace std;
 #define MAX 10001
int kosaraju(vector<int> v[100001],int ,int );
int main()
{ 
   int t;
   cin>>t;
  while(t--)
   {   vector<int> v[100001];
        int a,b ;
   	cin>>a>>b;
       for(int i=0;i<b;i++)
           {  int m,n;
               cin>>m>>n;
               v[m].push_back(n);
           }
      
         
         int ans=kosaraju(v,a,b); 
         cout<<ans<<endl;
         for(int i=0;i<=a+1;i++)
        {    v[i].clear();   
         }
           
   }
return 0;
}
int kosaraju(vector<int> v[100001], int N, int M)
{
    
}