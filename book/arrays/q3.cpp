//string rotation
#include<iostream>
#include<string>

using namespace std;

int isRotation(string s1,string s2)
{
    string s1s1 = s1+s1;
    int t = s1s1.find(s2);
    return t;
}
int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int no = isRotation(s1,s2);
    if(no>=0)
    {
        cout << "is a rotation";
    }
    else
    {
        cout << "is not a rotation";
    }

}
