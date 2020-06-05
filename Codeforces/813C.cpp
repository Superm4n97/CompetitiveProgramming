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
#define maxn            200005

using namespace std;

ll n,x;
vll G[maxn];
ll disA[maxn] , disB[maxn];

void dfs(ll u , ll p, ll type)
{
    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;
        if (type==1)disA[v] = disA[u]+1;
        else disB[v] = disB[u]+1;

        dfs(v,u,type);
    }
}

int main()
{
    scll(n,x);
    for (int i=0;i<n+4;i++)disA[i] = disB[i] = inf8;

    for (int i=1;i<n;i++){
        ll a,b;
        scll(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    disA[1] = 0;
    disB[x] = 0;
    dfs(1,0,1);
    dfs(x,0,2);

    ll ans = 0;

//    for (int i=1;i<=n;i++)cout << disA[i] << " ";
//    cout << endl;
//    for (int i=1;i<=n;i++)cout << disB[i] << " ";
//    cout << endl;

    for (int i=1;i<=n;i++){
        if (disB[i]<disA[i])ans = max(ans,disA[i]*2);
    }
    cout << ans << endl;



    return 0;
}
