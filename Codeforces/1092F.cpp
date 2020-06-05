#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,A[maxn] , sum[maxn] , S[maxn] , ans = 0;
vector < ll > G[maxn];

void build(ll u , ll p)
{
      sum[u] = A[u];
      S[u] = 0;

      for (int i=0 ; i<G[u].size();i++){
            ll v = G[u][i];

            if (v != p){
                  build(v,u);

                  sum[u]+=sum[v];
                  S[u] += S[v] + sum[v];
            }
      }
}

void rec(ll u , ll p)
{
      ans = max(S[u],ans);

      show(u);
      show(sum[u]);
      show(S[u]);
      show(ans);
      cout << endl;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v != p){
                  S[v] = S[u]+sum[u] - 2*sum[v];
                  if (u==1) sum[v] = sum[u]-sum[v]+A[v];
                  else sum[v] = sum[u]+A[v];

                  rec(v,u);
            }
      }
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      for (int i= 1 ; i<n ; i++){
            ll a, b;
            cin >> a >> b;

            G[a].push_back(b);
      }

      build(1,0);

      rec(1,0);

      cout << ans << endl;


      return 0;
}
