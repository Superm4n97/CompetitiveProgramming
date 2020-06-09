#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll n,m;
vll G[3005];
vector < pair < ll , ll > > vp;

void dfs(ll u)
{
    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];

        for (int i=0;i<G[v].size();i++){
            ll w = G[v][i];
            if (w==u)continue;
            vp.pb(mk(u,w));
        }
    }
}

int main()
{
    scll(n,m);
    for (int i=0;i<m;i++){
        ll a,b;
        scll(a,b);
        G[a].pb(b);
    }
    for (int i=1;i<=n;i++)dfs(i);
    //srt(vp);

//    for (int i=0;i<vp.size();i++)
//        cout << vp[i].first << " " << vp[i].second.first << " " << vp[i].second.second << endl;

    ll ans =0;
    map < pair < ll , ll >  ,ll > mp;
    for (int i=0;i<vp.size();i++){
        ll a = vp[i].first , b = vp[i].second;
        mp[mk(a,b)]++;
        ll t = mp[mk(a,b)];
        ans += t-1;
    }
    cout << ans << endl;

    return 0;
}
