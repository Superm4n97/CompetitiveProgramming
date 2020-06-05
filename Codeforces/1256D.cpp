#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n , k , j=0;
    scanf("%lld%lld",&n,&k);
    string s;
    cin >> s;
    vector < ll > pos;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='0')pos.push_back(i);
    }
    for(ll i=0;i<pos.size();i++)
    {
        ll mn=min(k,pos[i]-j);
        swap(s[pos[i]],s[pos[i]-mn]);
        j++;
        k-=mn;
    }
    cout << s << endl;
    }
}
