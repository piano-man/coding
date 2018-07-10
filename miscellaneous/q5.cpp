//fact digit sum
#include <bits/stdc++.h>
using namespace std;

string getans(int n)
{
    if(n==1)
    {
        return "0";
    }
    int num = n;
    int fact = 1;
    vector<int> v;
    int i = 1;
    while(num!=0)
    {
        fact = fact*i;
        if(fact==num)
        {
            v.push_back(i);
            break;
            num = num-fact;
        }
        else if(fact<num)
        {
            i++;
            if(i>9)
            {
                num = num-fact;
                v.push_back(9);
                i = 1;
                fact = 1;
            }
        }
        else if(fact>num)
        {
            while(fact>num)
            {
                fact = fact/i;
                i--;
            }
            v.push_back(i);
            num = num-fact;
            i=1;
            fact = 1;
        }
    }
    if(v.size()==1)
    {
        int digit = v[0];
        string s = "1";
        s = s+to_string(digit);
        return s;
    }
    if(v.size()==0)
    {
        return "-1";
    }
    else
    {
        sort(v.begin(),v.end());
        string s = "";
        int k;
        for(k=0;k<v.size();k++)
        {
            s+=to_string(v[k]);
        }
        return s;
    }
}

int main() {
	int t;
	cin >> t;
	int i;
	for(i=0;i<t;i++)
	{
	    int n;
	    cin >> n;
	    cout << getans(n);
	    cout << "\n";
	}
	return 0;
}