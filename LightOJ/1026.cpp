#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define pb push_back
#define inf 10000000000000016

#define maxn 10004

using namespace std;

vector < ll > G[maxn];
ll n , START[maxn], DIS[maxn] ,vis[maxn], timee;
vector < pair < ll , ll > > vp;
map < pair < ll, ll > , ll > mp;

void clean()
{
    timee = 1;
    memset(vis,0,sizeof(vis));
    memset(START,0,sizeof(START));
    memset(DIS,0,sizeof(DIS));

    for (int i=0;i<maxn;i++){
        G[i].clear();
        DIS[i] = inf;
    }
    mp.clear();
    vp.clear();
}

void vectorPush(ll u, ll v)
{
    if (u>v)swap(u,v);
    vp.pb({u,v});
}

void dfs(ll u, ll p)
{
    START[u] = timee++;
    DIS[u] = START[u];

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;

        if (!vis[v]){
            vis[v] = 1;
            dfs(v,u);

            if (DIS[v]>DIS[u] && mp[{u,v}]==0){

//                show(v);
//                show(u);
//                show(DIS[v]);
//                show(START[u]);

                //vp.pb({u,v});
                vectorPush(u,v);
                mp[{u,v}] = 1;
                mp[{v,u}] = 1;
            }
        }
        DIS[u] = min(DIS[v] , DIS[u]);
    }
}

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){
        clean();

        scanf("%lld",&n);

        for (int i=0;i<n;i++){
            ll u , k,a;
            scanf("%lld (%lld)",&u ,&k);

            while(k--){
                ll v;
                scanf("%lld",&v);

                if (!mp[{u,v}]){
                    G[u].pb(v);
                    G[v].pb(u);
                    mp[{u,v}] = 1;
                    mp[{v,u}] = 1;
                }
            }
        }

        mp.clear();

        for (int i=0 ; i<n ; i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(i,i);
            }
        }
//        for (int i=0;i<n;i++){
//            show(DIS[i]);
//            show(START[i]);
//            cout << endl;
//        }

        printf("Case %d:\n",_t);
        printf("%lld critical links\n",(ll)vp.size());

        if (!vp.empty())sort(vp.begin(),vp.end());

        for (int i=0;i<vp.size();i++){
            ll a = vp[i].first , b = vp[i].second;
            if (a>b)swap(a,b);
            printf("%lld - %lld\n",a,b);
        }

    }

    return 0;
}
