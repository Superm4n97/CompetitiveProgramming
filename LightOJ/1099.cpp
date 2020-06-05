#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl
#define maxn 5005
#define inf 100000000000000
using namespace std;

int main()
{
    ll tc;
    cin >> tc;

    for (int _t=1;_t<=tc;_t++){
        ll n,m;
        vector < ll > G[maxn],W[maxn] , A;
        vector < pair < pair < ll , ll > , ll > > E;
        map < pair < ll , ll > , ll > mp;
        ll destination[maxn] , source[maxn] , P[maxn];

        cin >> n >> m;
        for (int i=0;i<m;i++){
            ll a,b , c;
            cin >> a >> b >> c;

            E.pb({{a,b},c});

            G[a].pb(b);
            G[b].pb(a);

            W[a].pb(c);
            W[b].pb(c);
        }

        ///initialization
        for (int i=0;i<n+4;i++){
            destination[i] = inf;
            source[i] = inf;
            P[i] = i;
        }

        priority_queue < pair < ll , ll > > pq;

        ///distance from source
        source[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            ll u = pq.top().second, we = pq.top().first*-1;
            pq.pop();

            if (we!=source[u])continue;

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i] , cost = W[u][i];

                if (source[v]>source[u]+cost){
                    source[v] = source[u]+cost;
                    pq.push({source[v]*-1,v});
                    P[v] = u;
                }
            }
        }

        ///clear pq
        while(!pq.empty())pq.pop();

        /// distance from destination
        destination[n] = 0;
        pq.push({0,n});
        while(!pq.empty()){
            ll u = pq.top().second , we = pq.top().first*-1;
            pq.pop();

            if (we != destination[u])continue;

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i] , cost = W[u][i];

                if (destination[v]>destination[u]+cost){
                    destination[v] = destination[u]+cost;
                    pq.push({destination[v]*-1,v});
                }
            }
        }

        for (int i=0;i<m;i++){
            ll a = E[i].first.first , b = E[i].first.second , c = E[i].second;

            A.pb(source[a]+destination[b]+c);
            A.pb(source[b]+destination[a]+c);
        }
        sort(A.begin(),A.end());
        ll ans = 0;

        for (int i=0;i<A.size();i++){
            //show(A[i]);
            if (A[i]!=A[0]){
                ans = A[i];
                break;
            }
        }
        cout << "Case "<< _t << ": " << ans << endl;
    }


    return 0;
}
