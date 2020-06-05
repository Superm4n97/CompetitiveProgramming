#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,sum[maxn] , S[maxn] , A[maxn],total , ans = 0;
vector < ll > G[maxn];

void build(ll u, ll p)
{
      S[u] = 0;
      sum[u] = A[u];

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v != p){
                  build(v,u);

                  S[u] += S[v]+sum[v];
                  sum[u]+=sum[v];
            }
      }
}
void rec(ll u, ll p)
{
      ans = max(ans,S[u]);

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v != p){
                  S[v] = S[u] + total - 2*sum[v];

                  rec(v,u);
            }
      }
}

int main()
{
      cin >> n ;

      for (int i=1 ; i<=n;i++)cin >> A[i];
      for (int i=1 ; i<n;i++){
            ll a,b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }
      build(1,0);
      total = sum[1];
      rec(1,0);

      cout << ans << endl;

      return 0;
}
