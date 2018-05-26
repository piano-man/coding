//permutations of a string(error)
/*#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;


vector<string> permute(string str,int len)
{
    vector<string> v1;
    if(len==0)
    {
        v1.push_back("");
        return v1;
    }
    char first = str[0];
    cout << first;
    string remainder = str.substr(1);
    cout << remainder;
    vector<string> words = permute(remainder,len-1);
    cout << words.size();
    for(auto i:words)
    {
        cout << "inside";
        int j;
        if(i.length()==0)
        {
            string s = i.insert(0,1,first);
            v1.push_back(s);
        }
        else
        {
        for(j=0;j<i.length();j++)
        {
            string s = i.insert(j,1,first);
            cout << s;
            v1.push_back(s);       
        }
        }
    }
    return v1;
}
int main()
{
    vector<string> v1;
    string s1;
    cin >> s1;
    int l = s1.length();
    v1 = permute(s1,l);
    //cout << v1.size();
    for(auto i:v1)
    {
        cout << i << " ";
    }
}*/
#include <bits/stdc++.h>
using namespace std;

char s[100005];
int c[26];

void rec(int id, int l) {
	if(id == l) {
		s[id] = '\0';
		printf("%s\n", s);
		return;
	}
	int i;
	for(i = 0; i < 26; i++) {
		if(c[i]) {
			c[i]--;
			s[id] = (char)(i + 'a');
			rec(id + 1, l);
			c[i]++;
		}
	}
}

int main() {
	scanf("%s", s);
	int i;
	int l = strlen(s);
	for(i = 0; i < l; i++) {
		c[s[i] - 'a']++;
	}
	rec(0, l);
	return 0;
}