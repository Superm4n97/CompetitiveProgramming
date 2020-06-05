#include<bits/stdc++.h>
#define ll long long int
#define maxn 10004
#define inf 100000000000000
#define pb push_back

using namespace std;

struct edge{
    ll node;
    ll weight;
    ll type;
};

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){
        ll n,m,k,d;
        scanf("%lld %lld %lld %lld",&n,&m,&k,&d);

        vector < edge > G[maxn];
        ll A[maxn][12];

        for (int i=0;i<maxn;i++){
            for (int j=0;j<12;j++)A[i][j] = inf;
        }

        for (int i=0;i<m;i++){
            ll a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            G[a].pb({b,c,1});
            //G[b].pb({a,c,1});
        }
        for (int i=0;i<k;i++){
            ll a, b, c;
            scanf("%lld %lld %lld",&a,&b,&c);
            G[a].pb({b,c,2});
            //G[b].pb({a,c,2});
        }

        ///priority_queue       dis  node
        priority_queue < pair < ll , ll > > pq;
        A[0][0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            ll u = pq.top().second , dis = pq.top().first*-1;
            pq.pop();

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i].node , cost = G[u][i].weight , type = G[u][i].type;

                for (int j = 0 ; j<=d ; j++){
                    ll id = j;
                    if (type==2){
                        id++;
                        if (id>d)continue;
                    }

                    if (A[v][id] > A[u][j]+cost){
                        A[v][id] = A[u][j] + cost;
                        pq.push({A[v][id]*-1 , v});
                    }
                }
            }
        }
        ll ans = inf+inf;
        for (int i = 0;i<=d ; i++){
            ans = min(A[n-1][i],ans);
        }
        if (ans>=inf)printf("Case %d: Impossible\n",_t);
        else printf("Case %d: %lld\n",_t,ans);
    }


    return 0;
}
