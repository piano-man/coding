//multiply two strings
#include<bits/stdc++.h>
using namespace std;
 
string multiplyStrings(string , string );
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	
    	cout<<multiplyStrings(a,b)<<endl;
    }
     
}
string multiplyStrings(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    int start1=0,start2=0;
    int size1=l1,size2=l2;
    if(s1[0]=='-')
    {
        start1 = 1;
        size1 = l1-1;
    }
    if(s2[0]=='-')
    {
        start2 = 1;
        size2 = l2-1;
    }
    vector<int> result(size1+size2,0);
    if(l1==0||l2==0)
    {
        return 0;
    }
    int i_n1 = 0;
    int i_n2 = 0;
    int i,j;
    for(i=l1-1;i>=start1;i--)
    {
        i_n2 = 0;
        int carry = 0;
        int d1 = s1[i]-'0';
        for(j=l2-1;j>=start2;j--)
        {
            int d2 = s2[j]-'0';
            int mul = d1*d2;
            int sum = mul+result[i_n1+i_n2]+carry;
            carry = sum/10;
            result[i_n1+i_n2] = sum%10;
            i_n2++;
        }
        if(carry>0)
        {
            result[i_n1+i_n2] += carry;
        }
        i_n1++;
    }
    int k = result.size()-1;
    while(k>=0&&result[k]==0)
    {
        k--;
    }
    if(k==-1)
    {
        return "0";
    }
    string s;
    if((start1==1&&start2==1)||(start1==0&&start2==0))
    {
        s="";        
    }
        else
    {
        s="-";        
    }
    while (k>=0)
    {
        s+= to_string(result[k--]);
    }
        return s;        

}