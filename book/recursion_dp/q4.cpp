//balanced parenthesis
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

void addbrac(vector<string> &list,int leftrem,int rightrem,string str,int count)
{
    if(leftrem<0||rightrem<leftrem)
    {
        return;
    }
    if(leftrem==0&&rightrem==0)
    {
        string s = str;
        list.push_back(s);
    }
    else
    {
        if(leftrem>0)
        {
            str+='{';
            addbrac(list,leftrem-1,rightrem,str,count+1);
        }
        if(rightrem>leftrem)
        {
            str+='}';
            addbrac(list,leftrem,rightrem-1,str,count+1);
        }
    }
}

int main()
{
    int n;
    string str;
    cin >> n;
    vector<string> list;
    addbrac(list,n,n,str,0);
     //std::vector<std::string>::iterator it;
    //for(it = list.begin();it<list.end();it++)
    for(auto i:list)
    {
        cout << i << "\n";
    } 

}