//cutting binary string
#include<bits/stdc++.h>
using namespace std;
bool ispow(int res){
    while(res>0&&res%5==0){
    res/=5;    
    }
    if(res==1)return true;
    else return false;
    
}
int main()
 {
 int t,n;
 string s;
    cin>>t;
    while(t--){
    cin>>s;
    n=s.size();
    s="0"+s;
    int dp[n+1];
    for(int i=0;i<=n;i++)
    dp[i]=200;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        long res=0,pos=0;
        for(int j=i;j>=0;j--)
        {
            res+=(s[j]-'0')*pow(2,pos);
            pos++;
            if(s[j]=='1'&&ispow(res))
            {
                dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
    }
    if(dp[n]>=100)
    cout<<"-1\n";
    else
    cout<<dp[n]<<endl;
    }
	return 0;
}