///It will work for if a vertices is disconnected

#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

int N,M,P[maxn] , D[maxn],L[maxn],AP[maxn], vis[maxn] , Time = 1 , ans = 0;
vector < int > G[maxn],T[maxn];
map < pair < int , int > , int > EDG;

void clean()
{
      EDG.clear();
      for (int i=0;i<=N+2 ;i++){
            G[i].clear();
            T[i].clear();
            P[i] = -1;
            D[i] = L[i] = AP[i] = vis[i] = 0;
      }
      Time = 1;
      ans = 0;
}

void ArticulationPoint(int u, int p, int root)
{
      D[u] = L[u] = Time;
      Time++;
      int child = 0;

      for (int i=0 ; i<G[u].size();i++){
            int v = G[u][i];

            if (v==p)continue;

            if (D[v]){
                  L[u] = min(L[u],D[v]);
            }
            else {
                  ArticulationPoint(v,u,root);
                  child++;

                  L[u] = min(L[u],L[v]);
                  if (L[v]>=D[u]){
                        AP[u] = 1;
                  }
            }
      }
      if (u==root && child>1)AP[root] = 1;
}

void buildTree(int u)
{
      vis[u] = 1;

      for (int i=0;i<G[u].size();i++){
            int v = G[u][i];

            if (vis[v])continue;

            if (P[v]==-1)P[v] = P[u];
            else {
                  int a = P[u] , b = P[v];

                  if (a!=b && EDG[{a,b}]==0){
                        T[a].push_back(b);
                        T[b].push_back(a);

                        EDG[{a,b}] = EDG[{b,a}] = 1;
                  }
                  buildTree(v);
            }
      }
}

void dfs(int u)
{
      vis[u] = 1;

      if (T[u].size()==1)ans++;

      for (int i=0;i<T[u].size();i++){
            int v = T[u][i];

            if (!vis[v])dfs(v);
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%d %d",&N,&M);
            map < pair < int,int > , int >duplicate;

            for (int i=0 ; i<M;i++){
                  int a,b;
                  scanf("%d %d",&a,&b);

                  if (!duplicate[{a,b}]){
                        G[a].push_back(b);
                        G[b].push_back(a);

                        duplicate[{a,b}]++;
                        duplicate[{b,a}]++;
                  }
            }
            int start = -1;
            for (int i=0 ; i<N;i++){
                  if (!D[i]){
                        ArticulationPoint(i,-1,i);
                  }
                  if (AP[i]==1 || G[i].size()==1){
                        P[i] = i;
                        start = i;
                  }
            }

            //show(start);

            if (start==-1)printf("Case %d: 0\n",_t);
            else {
                  buildTree(start);
                  memset(vis,0,sizeof vis);
                  dfs(start);
                  ans++;
                  ans/=2;

                  printf("Case %d: %d\n",_t,ans);
            }

            clean();
      }

      return 0;
}
