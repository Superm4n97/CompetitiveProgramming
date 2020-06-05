
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;
#define maxn 300004
#define inf 1000000000012

using namespace std;

vector < ll > G[maxn];
ll n , L[maxn] , vis[maxn] , P[maxn] , S[maxn][30];

void BuildLCA()
{
    queue < ll > q;
    q.push(0);
    L[0] = 0;
    vis[0] = 1;
    P[0] = 0;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];
            if (!vis[v]){
                L[v] = L[u]+1;
                vis[v] = 1;
                P[v] = u;
                q.push(v);
            }
        }
    }

    for (int i=0;i<n;i++)S[i][0] = P[i];

    for (int j = 1 ; j<28 ; j++){
        for (int i=0;i<n;i++)S[i][j] = S[S[i][j-1]][j-1];
    }
}

ll LCA(ll a, ll b)
{
    if (L[a]>L[b])swap(a,b);

    for (int i=27;i>=0 ; i--){
        if (L[b] - (1<<i) >= L[a])b = S[b][i];
    }
    if (a==b)return a;
    for (int i=27;i>=0;i--){
        if (S[a][i] != S[b][i]){
            a = S[a][i];
            b = S[b][i];
        }
    }

    return S[a][0];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1;_t<=tc;_t++){

        ///**initialization
        for (int i=0;i<maxn;i++){
            G[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(P,0,sizeof(P));
        memset(L,0,sizeof(L));
        ///*********

        scanf("%lld",&n);
        for (int i=1;i<n;i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            G[a].pb(b);
            G[b].pb(a);
        }

        BuildLCA();

        ll query;
        cin >> query;
        while(query--){
            ll a, b;
            cin >> a >> b;
            cout << LCA(a,b) << endl;
        }
    }
    return 0;
}
