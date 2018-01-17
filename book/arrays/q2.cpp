//permutation check
#include<iostream>
#include<string>

using namespace std;
int check(string s1,string s2)
{
    int arr[258]={0};
    int arr2[258]={0};
    int i;
    for(i=0;i<s1.length();i++)
    {
        int val = s1[i];
        arr[val]++;

    }
    for(i=0;i<s2.length();i++)
    {
        int val = s2[i];
        arr2[val]++;
    }
    for(i=0;i<258;i++)
    {
        if(arr[i]!=arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;
    cout << check(s1,s2);
}