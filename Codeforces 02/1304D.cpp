#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn            100005

using namespace std;

ll n;
vector < ll > G[maxn];
ll P[maxn] , L[maxn], S[maxn][29] , vis[maxn];

void bfs()
{
    L[1] = 0;
    P[1] = -1;
    vis[1] = 1;
    queue < ll > q;
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for (ll i=0;i<G[u].size();i++){
            ll v = G[u][i];
            if (!vis[v]){
                P[v] = u;
                vis[v] = 1;
                q.push(v);
                L[v] = L[u]+1;
            }
        }
    }
}

ll lca(ll a, ll b)
{
    if (a==b)return a;
    if (L[a]>L[b])swap(a,b);
    for (ll i=28;i>=0;i--){
        if (L[b]-(1<<i) >= L[a])b = S[b][i];
    }
    if (a==b)return a;
    for (ll i = 28 ; i>=0 ; i--){
        if (S[a][i] != S[b][i]){
            a = S[a][i];
            b = S[b][i];
        }
    }
    return S[a][0];
}

bool ans;

int main()
{
    memset(S,-1,sizeof(S));
    cin >> n;
    for (int i=1;i<n;i++){
        ll a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    bfs();
    for (int i=1;i<=n;i++)S[i][0] = P[i];
    for (int j=0;j<28;j++){
        for (int i=1;i<=n;i++)S[i][j+1] = S[S[i][j]][j];
    }
    ll q;
    cin >> q;
    while(q--){
        ll a,b;
        cin >> a >> b;
        cout << lca(a,b) << endl;
    }
    return 0;
}
