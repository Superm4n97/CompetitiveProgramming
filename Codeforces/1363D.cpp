#include <bits/stdc++.h>
#define pb           push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf           1000000000013
#define maxn 200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n , zeroLagbe[maxn] , oneLagbe[maxn] , P[maxn] , ans = inf;
ll A[maxn], B[maxn] , C[maxn];
vector < ll > G[maxn];
vector < pair < ll , ll > > nodes;

void dfs(ll u, ll p)
{
      if (B[u] != C[u]){
            if (C[u]==0)zeroLagbe[u] = 1;
            else oneLagbe[u] = 1;
      }

      for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];

            if (v==p)continue;
            P[v] = u;
            dfs(v,u);

            zeroLagbe[u]+=zeroLagbe[v];
            oneLagbe[u] +=oneLagbe[v];
      }
}

void dfs2(ll u, ll p, ll per)
{
      if (u==1){
            ll temp = min(zeroLagbe[u],oneLagbe[u]);
            ans=(temp*2)*A[u];
      }
      else if (per>A[u]){
            ll temp = min(zeroLagbe[u] , oneLagbe[u]);
            ans -= (temp*2)*per;
            ans+=(temp*2)*A[u];
      }

      for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];

            if (v==p)continue;

            dfs2(v,u,min(per,A[u]));
      }
}

int main()
{
      cin >> n;
      ll z = 0 , o = 0;
      for (ll i=1 ; i<=n;i++){
            ll a, b, c;
            cin >> A[i] >> B[i]>> C[i];

            if (B[i] != C[i]){
                  if (C[i]==0)z++;
                  else o++;
            }

            nodes.pb({A[i],i});
      }
      for (int i=1; i<n;i++){
            ll a, b;
            cin >> a>> b;

            G[a].pb(b);
            G[b].pb(a);
      }

      if (z!=o){
            cout << -1 << endl;
            return 0;
      }


      dfs(1,0);

      dfs2(1,0,inf);

      cout << ans << endl;

      return 0;
}
