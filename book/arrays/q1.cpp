//unique chracters
#include<iostream>
#include<string>

using namespace std;
int isunique(string s)
{
    bool char_set[256];
    cout << char_set[1];
    int i;
    for(i=0;i<s.length();i++)
    {
        int val = s[i];
        if(char_set[val])
        {
            return 2;
        }
        else
        {
            char_set[val]=1;
        }
    }
    return 0;
}
int main()
{
    string s;
    cin >> s;
    cout << isunique(s);
}