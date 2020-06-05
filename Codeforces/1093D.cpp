#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005
#define inf 10000000000000016
#define mod 998244353

using namespace std;

ll n,m , P[maxn] , L[maxn] , ans;
vector < ll > G[maxn];
bool solution;

pair <ll, ll> bfs(ll source)
{
      queue < ll > q;
      q.push(source);

      L[source] = 0LL;
      ll even = 0LL , odd = 0LL;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            if (L[u]%2)odd++;
            else even++;

            for (int i=0 ; i<G[u].size(); i++){
                  ll v = G[u][i];

                  if (L[u]+1 < L[v]){
                        L[v] = L[u]+1;
                        q.push(v);
                  }
                  if (L[u]%2 == L[v]%2){
                        solution = false;
                  }
            }
      }
      return {even,odd};
}

void clean()
{
      for (int i=0;i<=n+2;i++){
            G[i].clear();
            L[i] = inf;
      }
      solution = true;
      ans = 1;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn-1 ; i++){
            P[i] = P[i-1]*2;
            P[i]%=mod;
      }

      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%I64d %I64d",&n,&m);

            clean();

            for (int i=0;i<m;i++){
                  ll a,b;
                  scanf("%I64d %I64d",&a,&b);

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            for (int i=1 ; i<=n;i++){
                  if (L[i] != inf)continue;

                  if (G[i].empty()){
                        ans*=3;
                        ans%=mod;
                  }
                  else {
                        pair <ll ,ll> pr = bfs(i);

                        ll temp = P[pr.first]+P[pr.second];
                        temp%=mod;

                        ans*=temp;
                        ans%=mod;
                  }
            }

            if (!solution)printf("0\n");
            else printf("%I64d\n",ans);
      }


      return 0;
}
