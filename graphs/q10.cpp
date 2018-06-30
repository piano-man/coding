//jumping numbers
#include<bits/stdc++.h>
using namespace std;

void bfs(int n,int num)
{
    queue<int> q;
    q.push(num);
    while(!q.empty())
    {
        num = q.front();
        q.pop();
        if(num<=n)
        {
            cout << num << " ";
            int ld = num%10;
            if(ld==0)
            {
                q.push(num*10+(ld+1));
            }
            else if(ld==9)
            {
                q.push(num*10+(ld-1));
            }
            else
            {
                q.push(num*10+(ld-1));
                q.push(num*10+(ld+1));
            }
        }
    }
}

void printjumping(int n)
{
    int i;
    cout << 0 << " ";
    for(i=1;i<=9&&i<=n;i++)
    {
        bfs(n,i);
    }
}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<int> numbers;
    for(i=0;i<t;i++)
    {
        int k;
        cin >> k;
        numbers.push_back(k);
    }
    for(i=0;i<t;i++)
    {
        printjumping(numbers[i]);
    }
}