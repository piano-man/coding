//longest repeating non-overlapping substring
//uses up too much space
#include <bits/stdc++.h>
using namespace std;

string longest(string s)
{
    map<string,pair<int,int> > m1;
    int l = s.length();
    int max = 0;
    int start=0,end=0;
    int sublen,i;
    for(sublen=1;sublen<=l;sublen++)
    {
        for(i=0;i<l-sublen+1;i++)
        {
            int j = i+sublen-1;
            string temp = s.substr(i,sublen);
            if(m1.find(temp)!=m1.end())
            {
                if(m1[temp].second<i)
                {
                    if(sublen>max)
                    {
                        max = sublen;
                        start = i;
                        end = j;
                    }
                }
            }else{
                        m1[temp] = {i,j};
            }

        }
    }
    if(max>0)
    {
        return s.substr(start,end-start+1);
    }
    return "-1";
}

int main() {
	int t;
	cin >> t;
	int i;
	for(i=0;i<t;i++)
	{
        int n;
        cin >> n;
	    string s;
	    cin >> s;
	    cout << longest(s);
        cout << "\n";
	}
	return 0;
}