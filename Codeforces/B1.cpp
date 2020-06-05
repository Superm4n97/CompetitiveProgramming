#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int i;
    string s,p,ans;
    cin >> s;
    p=s;
    //cout << p << endl;
    reverse(p.begin(),p.end());
    //cout << p << endl;
    if(s==p)
    {
        cout << s << endl;
    }
    else
    {
        for(i=1;i<p.size();i++)
        {
            char c=p[i];
            s+=c;
            string k=s;
            reverse(k.begin(),k.end());
            if(k==s)
            {
                cout << s << endl;
                return 0;
            }
        }
        cout << endl;
    }
}
