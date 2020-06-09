#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008

using namespace std;

map < ll , ll > mp;

int main()
{
    string s;
    cin >> s;
    ll total = 0;
    for (int i=1;i<s.size();i++){
        if (s[i]=='v' && s[i-1]=='v'){
            mp[i] = mp[i-1]+1;
        }
        else mp[i] = mp[i-1];
    }
    ll temp = 0 , ans = 0;
    //cout << total << endl;
    for (int i=0;i<s.size();i++){
        if (s[i]=='o'){
            ll temp = s.size()-1;
            ans+=(mp[i]*(mp[temp]-mp[i]));
        }
    }
    cout << ans << endl;

    return 0;
}
