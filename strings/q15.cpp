//rotated string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int checkrotation(string s1,string s2)
{
    string temp = s1+s1;
    int ans =  temp.find(s2);
    return ans;

}

int main()
{
    string s1="amazon";
    string s2="azonam";
    int ans = checkrotation(s1,s2);
    if(ans>s1.length())
    {
        cout << "not a rotation";
    }
    else
    {
        cout << "rotation";
    }
}