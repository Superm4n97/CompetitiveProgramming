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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            100005

using namespace std;

vll vv;
vector < pll > vp;

int main()
{
    ll n,m;
    scl(n);
    for (int i=1;i<=n;i++){
        ll a;
        scl(a);
        vv.pb(a);
        vp.pb({a,i*-1});
    }
    rsrt(vp);
    scl(m);
    for (int i=0;i<m;i++){
        ll k, pos;
        scll(k,pos);
        vll v;
        for (int i=0;i<k;i++){
            v.pb(vp[i].second);
        }
        pos--;
        rsrt(v);
        cout << vv[v[pos]*-1-1] << endl;
    }



    return 0;
}
