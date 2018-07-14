//string comparision
#include<bits/stdc++.h>
using namespace std;

int compare(char c1,char c2)


int comparision(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int i;
    for(i=0;i<min(l1,l2);i++)
    {
        char c1 = s1[i];
        char c2 = s2[i];
        string a="",b="";
        if(c1=='n')
        {
            if
        }
        if(compare(c1,c2)>0)
        {
            return 1;
        }
        else if(compare(c1,c2)<0)
        {
            return -1;
        }
        else
        {
            continue;
        }
    }
    if(l1>l2)
    {
        return 1;
    }
    else if(l1<l2)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        cout << comparision(s1,s2);
    }
}