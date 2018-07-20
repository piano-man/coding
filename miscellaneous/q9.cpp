//decimal to base62
using namespace std;

string idtourl(unsigned long int n)
{
    string m = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string url = "";
    while(n)
    {
        url+=m[n%62];
        n=n/62;
    }
    reverse(url.begin(),url.end());
    return url;
    
}

int val(char ch)
{
    if(ch>='a'&&ch<='z')
    {
        return ch-'a';
    }
    else if(ch>='A'&&ch<='Z')
    {
        return ch-'A'+26;
    }
    else if(ch>='0'&&ch<='9')
    {
        return ch-'0'+52;
    }
}

unsigned long int urltoid(string s)
{
    unsigned long int power = 1;
    int base = 62;
    unsigned long int res = 0;
    int i;
    for(i=s.length()-1;i>=0;i--)
    {
        res+=val(s[i])*power;
        power = power*base;
    }
    return res;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    unsigned long int n;
	    cin >> n;
	    string s = idtourl(n);
	    unsigned long int id = urltoid(s);
	    cout << s << "\n";
	    cout << id << "\n";
	}
	return 0;
}