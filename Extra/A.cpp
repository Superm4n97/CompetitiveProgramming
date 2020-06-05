#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000000

using namespace std;

ll n,m,source,destination,L[maxn],C[maxn],vis[maxn], subLevel[maxn] , d , N = 0;
vector < ll > G[maxn];

void bfs()
{
      queue < ll > q;
      q.push(source);
      L[source] = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();
            N = max(N,L[u]);

            if (u==destination){
                  d = L[u];
            }

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  if (L[v]>L[u]+1){
                        L[v] = L[u]+1;
                        q.push(v);
                  }
            }
      }
}

void findSubLevels(ll u)
{
      subLevel[L[u]]++;
      vis[u] = 1;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (L[v] == L[u]+1 && vis[v]==0)findSubLevels(v);
      }
}

int main()
{
      cin >> n >> m >> source >> destination;

      for (int i=0;i<=n;i++)L[i] = maxn;

      for (int i = 0 ;i<m ; i++){
            ll a, b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      bfs();

      for (int i=1; i<=n;i++)C[L[i]]++;
      for (int i=1;i<=N ; i++)C[i] += C[i-1];

      findSubLevels(destination);

      ll ans = 0;

      for (int i=2 ;i<=N ; i++){
            if (i<=d){
                  ans += C[i-2];
            }
            else {
                  ll x = 2*d-i-2;

                  if (x>=0){
                        ans+=C[x]*subLevel[i];
                  }
            }
      }

      //for (int i=0 ; i<=N ; i++)cout << i << " : " << C[i] << endl;

      cout << n*(n-1)/2 - (ans+m) << endl;


      return 0;
}
