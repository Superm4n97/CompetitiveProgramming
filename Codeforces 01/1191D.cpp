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

vll v;
ll mx = 0 , x = 0;
map < ll , ll > mp;

int main()
{
    ll n;
    scl(n);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        v.pb(a);
        mp[a]++;
        if (mx==2 && mp[a]==2)mx = 3;
        if ((mp[a]==2 && mp[a-1]) || (mp[a] && mp[a+1]==2)) mx = 3;
        //cout << "mx " << mx << "      mp[a] " << mp[a] << endl;
        mx = max(mx,mp[a]);
    }
    if (mp[0]>1)mx = 3;

    srt(v);
    for (int i=0;i<n;i++){
        x+=(v[i]-i);
    }
    if (mx>2)cout << "cslnb" << endl;///**
    else if (x%2)cout << "sjfnb" << endl;
    else if (x%2==0)cout << "cslnb" << endl;


    return 0;
}
