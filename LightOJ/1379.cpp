#include<bits/stdc++.h>
#define ll long long int
#define maxn 10004
#define inf 100000000000000
#define pb push_back

using namespace std;

struct edge{
    ll node;
    ll weight;
};

struct node
{
    ll aa;
    ll bb;
    ll cc;
};

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){
        ll n,m,s,t,p;

        scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&t,&p);

        vector < edge > G[maxn],H[maxn];
        vector < node > E;
        ll A[maxn] , B[maxn];

        for (int i=0;i<maxn;i++){
            A[i] = inf;
            B[i] = inf;
        }

        for (int i=0;i<m;i++){
            ll a,b , c;
            scanf("%lld %lld %lld",&a,&b,&c);

            E.pb({a,b,c});
            G[a].pb({b,c});
            H[b].pb({a,c});
        }

        A[s] = 0 , B[t] = 0;
        priority_queue < pair < ll , ll > > pq;

        pq.push({0,s});

        while(!pq.empty()){
            ll u = pq.top().second;
            pq.pop();

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i].node , cost = G[u][i].weight;

                if (A[v] > A[u]+cost){
                    A[v] = A[u]+cost;
                    pq.push({A[v]*-1,v});
                }
            }
        }

        while(!pq.empty())pq.pop();

        pq.push({0,t});
        while(!pq.empty()){
            ll u = pq.top().second;
            pq.pop();

            for (int i=0;i<H[u].size();i++){
                ll v = H[u][i].node , cost = H[u][i].weight;

                if (B[v]>B[u]+cost){
                    B[v] = B[u]+cost;
                    pq.push({B[v]*-1,v});
                }
            }
        }

        ll ans = -1;

        for (int i=0;i<m;i++){
            ll a = E[i].aa , b = E[i].bb , c = E[i].cc;
            ll temp = A[a]+B[b]+c;

            if (temp<=p)ans = max(c,ans);
        }

        printf("Case %d: %lld\n",_t,ans);

    }


    return 0;
}
