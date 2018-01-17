//longest common substring(dynamic programming)
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<stdlib.h>
using namespace std;

void printLCS(vector<string> v,int l1,int l2)
{
    int len = 0;
    int row,col;
    string s1 = v[0];
    string s2 = v[1];
    int table[l1+1][l2+1];
    int i , j ;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
                if(len<table[i][j])
                {
                    len = table[i][j];
                    row = i;
                    col = j;
                }

            }
            else
            {
                table[i][j]=0;
            }

        }
    }
    if(len==0)
    {
        cout << -1 ;
    }
    else
    {
        cout << len;
        cout << "\n";
        char* result = (char*)malloc((len + 1) * sizeof(char));
        int k=0;
        while(row!=0 && col!=0)
        {
                if(table[row][col]!=0)
                {
                    result[--len]=s1[row-1];
                    row=row-1;
                    col=col-1;   
                }
                else
                {
                    break;
                }

        }
        cout << result;       
    }

}

int main()
{
    int cases;
    cin >> cases;
    int i;
    int arr[200][200];
    vector<vector<string> > v;
    for(i=0;i<cases;i++)
    {
        v.push_back(vector<string>());
    }
    for(i=0;i<cases;i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
        string n1;
        cin >> n1;
        v[i].push_back(n1);
        string n2;
        cin >> n2;
        v[i].push_back(n2);

    }
    for(i=0;i<cases;i++)
    {
        printLCS(v[i],arr[i][0],arr[i][1]);
    }
}
