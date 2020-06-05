#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define maxn 5003
#define maxn 10000007

using namespace std;

int n,m,vis[maxn] , L[maxn] , solution = 1 , DP[maxn][maxn];
vector < int > G[maxn] ;
vector < pair <int,int> > vp;

pair <int , int> bfs(int s)
{
      queue < int > q;
      q.push(s);
      L[s] = 0;

      int even = 0 , odd = 0;

      while(!q.empty()){
            int u = q.front();
            q.pop();

            if (L[u]%2)odd++;
            else even++;

            for (int i=0 ; i<G[u].size() ; i++){
                  int v = G[u][i];

                  if (L[v] == -1){
                        L[v] = L[u]+1;
                        q.push(v);
                  }

                  if (L[u]%2 == L[v]%2)solution = 0;
            }
      }

      return {even,odd};
}

int main()
{
      scanf("%d %d",&n,&m);
      for (int i=0;i<m;i++){
            int a, b;
            scanf("%d %d",&a,&b);

            G[a].push_back(b);
            G[b].push_back(a);
      }

      memset(L,-1,sizeof L);
      memset(DP,-1,sizeof DP);

      for (int i=1 ; i<=n;  i++){
            if (!vis[i])vp.push_back(bfs(i));
      }

      if (!solution)printf("")


      return 0;
}
