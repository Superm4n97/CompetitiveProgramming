#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

int CP[maxn],D[maxn],L[maxn],P[maxn],Time = 1,vis[maxn],N,M,ans = 0;
vector < int > G[maxn],T[maxn];
map < pair < int ,int > , int > EDG;

void clean()
{
      for (int i=0 ;i<=N+1 ; i++){
            G[i].clear();
            T[i].clear();
            P[i] = -1;
            vis[i] = D[i] = CP[i] = L[i] = 0;
      }
      ans = 0;
      Time = 1;
      EDG.clear();
}

void CriticalPoints(int u, int p)
{
      D[u] = L[u] = Time;
      Time++;

      //if (G[u].size()==1)CP[u] = 1;

      for (int i=0 ; i<G[u].size();i++){
            int v = G[u][i];

            if (v==p)continue;

            if (!D[v]){
                  CriticalPoints(v,u);
                  L[u] = min(L[u],L[v]);

                  if (L[v]>D[u]){
                        CP[u] = CP[v] = 1;
                  }
            }
            else {
                  L[u] = min(L[u],D[v]);
            }
      }
}

void DFS(int u)
{
      vis[u] = 1;

      for (int i=0 ; i<G[u].size();i++){
            int v = G[u][i];

            if (vis[v])continue;

            int a = P[u] , b = P[v];

            if (b==-1)P[v] = a;
            else {
                  if (!EDG[{a,b}]){
                        T[a].push_back(b);
                        T[b].push_back(a);

                        EDG[{a,b}] = EDG[{b,a}] = 1;
                  }
            }

            DFS(v);
      }
}

void DFS2nd(int u)
{
      vis[u] = 1;

      if (T[u].size()==1)ans++;

      for (int i=0 ; i<T[u].size();i++){
            int v = T[u][i];

            if (vis[v])continue;

            DFS2nd(v);
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%d %d",&N,&M);

            map < pair < int, int > , int > duplicate;

            for (int i = 0 ;i<M ; i++){
                  int a,b;
                  scanf("%d %d",&a,&b);

                  if (!duplicate[{a,b}]){
                        G[a].push_back(b);
                        G[b].push_back(a);

                        duplicate[{a,b}] = 1;
                        duplicate[{b,a}] = 1;
                  }
            }

            int start = -1;

            CriticalPoints(0,-1);

            for (int i=0 ; i<N ; i++){
                  if (CP[i]==1){
                        P[i] = i;
                        start = i;
                  }
            }

            //show(start);

            if (start == -1){
                  printf("Case %d: 0\n",_t);
            }
            else {
                  DFS(start);
                  memset(vis,0,sizeof vis);
                  DFS2nd(start);
                  ans++;
                  ans/=2;

                  printf("Case %d: %d\n",_t,ans);
            }

            clean();
      }

      return 0;
}
