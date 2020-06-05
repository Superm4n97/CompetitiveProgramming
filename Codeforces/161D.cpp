#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 50005

using namespace std;

ll n,k , dp[maxn][505] , ans = 0;
vector < ll > G[maxn];

void dfs(ll u , ll p)
{
      dp[u][0] = 1;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v==p)continue;

            dfs(v,u);

            for (int j=1 ; j<k ; j++){
                  ll temp = ans;

                  ans += (dp[v][j-1]*dp[u][k-j]);

                  /*if (ans!=temp){
                        show(ans);
                        show(v);
                        show(j);
                        show(u);
                  }*/

            }
            ans+=dp[v][k-1];

            /*show(ans);
            show(v);
            show(dp[v][k-1]);
            cout << endl;*/

            for (int j=1 ; j<=k ; j++){
                  dp[u][j] += dp[v][j-1];
            }
      }
      //ans+=dp[u][k];
}

int main()
{
      scanf("%I64d %I64d",&n,&k);

      for (int i=1; i <n;i++){
            ll a,b;
            scanf("%I64d %I64d",&a,&b);

            G[a].push_back(b);
            G[b].push_back(a);
      }
      dfs(1,0);

      printf("%I64d\n",ans);


      return 0;
}
