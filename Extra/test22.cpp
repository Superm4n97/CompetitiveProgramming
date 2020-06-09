#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
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

vector < pll > v;

int main()
{
    ll n;
    scl(n);

    for (int i=0;i<n;i++){
        ll a,b;
        scll(a,b);

        v.pb({b,a});
    }
    srt(v);
    ll time = 0 , cnt = 0;

    for (int i=0 ; i<n; i++){
        time+=v[i].second;
        if (time<=v[i].first)cnt++;
    }
    cout << (cnt==n?"Yes":"No") << endl;

    return 0;
}

