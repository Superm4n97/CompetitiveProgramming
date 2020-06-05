#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define pb push_back
#define maxn 105
#define inf 100000000000000

using namespace std;

struct edge
{
    ll node;
    ll weight;
};

int main()
{
    int tc;
    scanf("%d",&tc);

    for (int _t = 1; _t<=tc; _t++){
        ll n,m;
        scanf("%lld %lld",&n,&m);

        ll F[maxn];
        vector < edge > G[maxn];

        for (int i=0;i<n;i++)scanf("%lld",&F[i]);
        for (int i=0;i<m;i++){
            ll a, b , c;
            scanf("%lld %lld %lld",&a,&b,&c);
            G[a].pb({b,c});
            G[b].pb({a,c});
        }

        ll q;
        scanf("%lld",&q);
        printf("Case %d:\n",_t);

        while(q--){
            ll c,s,t;
            scanf("%lld %lld %lld",&c,&s,&t);

            ll A[maxn];
            priority_queue <  pair < ll , ll > > pq, P[maxn];

            for (int i=0;i<n+4;i++)A[i] = inf;
            A[s] = 0;

            pq.push({0,s});
            while(!pq.empty()){
                ll u = pq.top().second;
                pq.pop();

                P[u].push({F[u]*-1,c});

                for (int i=0;i<G[u].size();i++){
                    ll v = G[u][i].node , w = G[u][i].weight;


                    priority_queue < pair < ll , ll > > ppq;
                    ppq = P[u];

                    if (w<=c){
                        ll cost = 0;
                        while(!ppq.empty()){
                            ll ccost = ppq.top().first*-1 , capacity = ppq.top().second;
                            ppq.pop();

                            cost += min(capacity,w)*ccost;
                            w -= min(capacity,w);

                            if (capacity - min(capacity,w) > 0){
                                ppq.push({ccost*-1,capacity - min(capacity,w)});
                            }

                            if (w<=0)break;
                        }

                        if (A[v] > A[u]+cost){
                            P[v] = ppq;
                            A[v] = A[u]+cost;

                            pq.push({F[u],v});
                        }
                        if (u==2 && v==3){
                            show(u);
                            show(A[u]);
                            show(v);
                            show(A[v]);
                            show(cost);
                            cout << endl;
                        }
                    }
                }
            }

            if (A[t]>=inf)printf("impossible\n");
            else printf("%lld\n",&A[t]);
        }
    }



    return 0;
}
