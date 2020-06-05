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

ll A[maxn][5] , sz[maxn] , mark[maxn];
map < pll , ll > mp;

vector < ll > G[maxn];

void make(ll a, ll b)
{
    if (mp[{a,b}]==0){
        mp[{a,b}]++;
        mp[{b,a}]++;

        G[a].pb(b);
        G[b].pb(a);

        sz[a]++ , sz[b]++;
    }
}

void dfs(ll u,ll nextsc)
{
    cout << u << " ";
    mark[u] = 1;
    ll nextSource = 0;
    vector < pll > vc;
    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        sz[v]--;
        if (mark[v]==0)vc.pb({sz[v],v});
    }
    if (!vc.empty()){
        srt(vc);
        if (vc.size()==1)dfs(vc[0].second,-1);
        else {
            if (nextsc==0 || nextsc==vc[0].second)dfs(vc[0].second,vc[1].second);
            else dfs(vc[1].second,vc[0].second);
        }
    }
}

int main()
{
    ll n;
    scl(n);
    for (int i=1;i<=n-2;i++){
        ll a, b, c;
        scll(a,b);
        scl(c);

        make(a,b);
        make(b,c);
        make(c,a);
    }
    ll source = 0;
    for (int i=1;i<=n;i++){
        if (sz[i]==2){
            source = i;
            break;
        }
    }

    dfs(source , 0);


    return 0;
}
