#include<bits/stdc++.h>

#define ll long long int
#define inf 100000000000000
#define maxn 100005
#define pb push_back

using namespace std;

vector < ll > G[maxn] , W[maxn];
ll n,m , cost[maxn];
map < pair < ll , ll > , ll > mp;

ll dijkstra()
{
    priority_queue < pair <ll,ll> > pq;
    pq.push({0,1});
    cost[1] = 0;

    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();

        cout << "u: " << u << endl;

        for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];
            ll w = W[u][i];
            if (cost[v]>cost[u]+w){
                cost[v] = cost[u]+w;
                pq.push({cost[v]*-1 , v});
            }
        }
    }
    return cost[n];
}

int main()
{
    for (int i=0;i<=n+3;i++)cost[i] = inf;

    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a, b , w;
        cin >> a>> b>> w;
        //if (mp[{a,b}]!=0){
            G[a].pb(b);
            G[b].pb(a);
            W[a].pb(w);
            W[b].pb(w);
        //}

    }
    ll temp = dijkstra();
    if (temp>inf)cout << -1 << endl;
    else cout << temp << endl;

    return 0;
}
