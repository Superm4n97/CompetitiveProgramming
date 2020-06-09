#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n , S[maxn], A[maxn], ans = 0 ;
vector < ll > G[maxn];
bool solution = true;

void dfs(ll u, ll p)
{
      //show(u);
      if (S[u]==-1){
            for (int i=0;i<G[u].size();i++){
                  ll v = G[u][i];
                  if (v==p)continue;

                  if (S[u]==-1)S[u] = S[v];
                  else {
                        S[u] = min(S[u],S[v]);
                  }
            }
            if (S[u]==-1)S[u] = S[p];
      }
      if (S[p]>S[u])solution  = false;

      if (u != 1)A[u] = S[u] - S[p];

      for (int i=0 ; i<G[u].size();i++){
            ll v = G[u][i];

            if (v==p)continue;

            dfs(v,u);
      }
}

int main()
{
     cin >> n;
     for (int i=2 ; i<=n;i++){
            ll a;
            cin >> a;

            G[a].push_back(i);
            G[i].push_back(a);
     }
     for (int i=1 ;i<=n;i++){
            cin >> S[i];
     }
     A[1] = S[1];
     dfs(1,0);

     if (!solution){
            cout << -1 << endl;
            return 0;
     }

     for (int i=1;i<=n;i++)ans+=A[i];

     cout << ans << endl;

      return 0;
}
