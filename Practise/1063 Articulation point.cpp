#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
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
#define mk              make_pair
#define inf8            100000008
#define printCaseAnsInt(t,ans)  printf("Case %d: %d\n",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld\n",t,ans)

using namespace std;

ll n,m , ans ,  id;
ll L[20005] , D[20005];
vector < ll > G[20005];
map < ll , ll > mp;

ll bridge(ll u, ll p)
{
    L[u] = id;
    D[u] = id++;

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;
        if (D[v]==0){
            L[u] = min(bridge(v,u) , L[u]);
            if (L[v]>D[u]){
                if (G[u].size()>1 && !mp[u]){
                    ans++;
                    mp[u] = 1;
                }
                if (G[v].size()>1 && !mp[v]){
                    ans++;
                    mp[v] = 1;
                }
            }
        }
        else L[u] = min(L[u] , D[v]);
    }
    return L[u];
}

int main()
{
    int tc;
    scd(tc);
    for (ll _t=1;_t<=tc;_t++){
        scll(n,m);
        for (int i=0;i<m;i++){
            ll a,b;
            scll(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        ans = 0 , id = 1;

        for (int i=1;i<=n;i++){
            if (D[i]==0)ll temp = bridge(i,0);
        }

        printCaseAnsLL(_t,ans);
        for (int i=1;i<=n;i++){
            G[i].clear();
            L[i] = 0;
            D[i] = 0;
        }
        mp.clear();
    }

    return 0;
}
