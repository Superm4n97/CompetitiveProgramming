#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

vector < int > G[maxn];
int AP[maxn],D[maxn],Low[maxn] , Time = 1 , N;

void clean()
{
      Time = 1;
      for (int i=0 ; i<=N+1;i++){
            G[i].clear();
            AP[i] = D[i] = Low[i] = 0;
      }
}

void ArticulationPoint(int u, int p, int root)
{
      D[u] = Low[u] = Time;
      Time++;

      int cnt = 0 , mn = D[u];

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v==p)continue;

            if (D[v]){
                  Low[u] = min(Low[u],D[v]);
            }
            else {
                  ArticulationPoint(v,u,root);
                  cnt++;

                  if (u!=root && Low[v]>=D[u])AP[u]=1;

                  Low[u] = min(Low[u],Low[v]);
            }
      }

      if (u==root && cnt>1)AP[root] = 1;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            int m , ans = 0;
            scanf("%d %d",&N,&m);

            map < pair <int , int> , int > mp;

            for (int i=0 ; i<m; i++){
                  int a, b;
                  scanf("%d %d",&a,&b);

                  if (!mp[{a,b}]){
                        G[a].push_back(b);
                        G[b].push_back(a);

                        mp[{a,b}]++;
                        mp[{b,a}]++;
                  }
            }

            for (int i=1 ; i<=N ; i++){
                  if (!D[i])ArticulationPoint(i,-1,i);
            }
            for (int i=1 ; i<=N;i++){

                  if (AP[i] == 1){
                        ans++;
                  }
            }
            printf("Case %d: %d\n",_t,ans);

            clean();
      }

      return 0;
}
