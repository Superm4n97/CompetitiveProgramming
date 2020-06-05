#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define inf 1000000000000
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < ll > G[5005] ;

ll aa[5005] , bb[5005] , cc[5005] , x[5005] , y[5005];

map < pair < ll ,ll > , ll > index;

bool ans = true;

bool dfs(ll u , ll p , ll d, ll cost)
{
    if (u==d)return true;

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;

        ll temp = dfs(v,u,d,cost);

        if (temp){
            index[{u,v}] = index[{v,u}] = max(index[{u,v}],cost);
            return true;
        }
    }
    return false;
}

ll dfsCheck(ll u, ll p, ll d)
{
    if (u==d)return inf;

    for (int i=0;i<G[u].size();i++){
        ll v = G[u][i];
        if (v==p)continue;

        ll temp = dfsCheck(v,u,d);

        if (temp){
            return min(temp,index[{u,v}]);
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n;
    scanf("%lld",&n);

    for (int i=1;i<n;i++){
        scanf("%lld %lld",&x[i],&y[i]);

        if (x[i]>y[i])swap(x[i],y[i]);

        G[x[i]].pb(y[i]);
        G[y[i]].pb(x[i]);
    }
    ll q;
    scanf("%lld",&q);
    for (int i=0;i<q;i++){
        scanf("%lld %lld %lld",&aa[i],&bb[i],&cc[i]);
        dfs(aa[i],0,bb[i],cc[i]);
    }

    for (int i=0;i<q;i++){
        ll temp = dfsCheck(aa[i],0,bb[i]);
        if (temp != cc[i]){
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 1 ; i<n;i++){
        //if (val[i]==-1)val[i] = 1;
        //cout << val[i] << " ";
        printf("%lld ",max(index[{x[i],y[i]}],1LL));
    }
    printf("\n");

    return 0;
}
