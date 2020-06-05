#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;
#define maxn 200005
#define inf 1000000000012

using namespace std;

vector < ll > G[maxn];
ll n ,k, A[maxn] , L[maxn] , vis[maxn] , P[maxn];
ll S[maxn][30];
ll indexx = 0LL;

void BuildLCA()
{
    queue < ll > q;
    q.push(1);
    L[1] = 0;
    vis[1] = 1;
    P[1] = 1;

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

    for (int i= 1;i<=n;i++)S[i][0] = P[i];

    for (int j = 1 ; j<28 ; j++){
        for (int i=1;i<=n;i++)S[i][j] = S[S[i][j-1]][j-1];
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
    ll tc;
    //scanf("%lld",&tc);

    for (int _t=1;_t<=1;_t++){

        ///**initialization
        for (int i=0;i<maxn;i++){
            G[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(P,0,sizeof(P));
        memset(L,0,sizeof(L));
        memset(A,0,sizeof(A));
        memset(S,-1,sizeof(S));
        indexx = -1;
        ///*********

        cin >> n >> k;

        for (int i=1;i<n;i++){
            ll a, b;
            cin >> a >> b;

            G[a].pb(b);
            G[b].pb(a);
        }

        BuildLCA();

        memset(vis,0,sizeof(vis));

        vis[0] = 1;


        while(k--){
            ll temp;
            cin >> temp;

            priority_queue < pair < ll , ll > > pq;

            for (int i=0;i<temp;i++){
                  ll a;
                  cin >> a;
                  pq.push({L[a],a});
            }

            bool ans = true;

            while(!pq.empty()){
                  if (pq.size()==1)break;

                  pair < ll , ll > a = pq.top();
                  pq.pop();
                  pair < ll , ll > b = pq.top();
                  pq.pop();

                  ll lc = LCA(a.second,b.second);

                  if (lc==b.second){
                        pq.push(b);
                        continue;
                  }

                  if(b.first-L[lc] >   1){

                        ans = false;
                        break;
                  }
                  pq.push({L[lc],lc});
            }
            if (ans)cout << "YES" <<endl;
            else cout << "NO" << endl;
        }

    }
    return 0;
}
