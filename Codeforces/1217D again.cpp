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

map < pll , int > mp;
vector < ll > G[5005];
ll ans = 1 ,n, m , mark[5005];
vector < pll > v;

void dfs(ll u)
{
    mark[u] = 1;

    for (int i=0;i < G[u].size() ; i++){
        ll v = G[u][i];
        if (mark[v] == 1){ /// backEdge
            mp[{u,v}] = 1;
            ans = 2;
        }
        else if (mark[v] == 0){
            dfs(v);
        }
    }
    mark[u] = 2;
}

int main()
{
    scll(n,m);

    for (int i=0 ; i<m; i++){
        ll a,b;
        scll(a,b);
        G[a].pb(b);
        v.pb({a,b});
    }

    for (int i=1;i<=n;i++){
        if (mark[i] == 0)dfs(i);
    }

    cout << ans << endl;
    for (int i=0; i<m; i++){
        cout << mp[{v[i].first,v[i].second}]+1 << " ";
    }


    return 0;
}
