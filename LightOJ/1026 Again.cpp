#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

int n , Low[maxn],Discovary[maxn],Time = 1;
vector < int > G[maxn];
vector < pair < int , int > > ans;

void clean()
{
      ans.clear();
      Time = 1;
      for (int i=0 ; i<=n+1 ; i++)G[i].clear(), Discovary[i] = 0;
}

void Bridge(ll u, ll p)
{
      Discovary[u] = Low[u] = Time;
      Time++;

      for (int i=0 ; i<G[u].size();i++){
            ll v = G[u][i];

            if (v!=p){
                  if (!Discovary[v])Bridge(v,u);

                  if (Low[v]>Discovary[u]){
                        ans.push_back({min(u,v),max(u,v)});
                  }
                  Low[u] = min(Low[u],Low[v]);
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%d",&n);

            map < pair <int , int> , int > EDGE;

            for (int i=0 ; i<n; i++){
                  int u , ed;
                  scanf("%d (%d)",&u,&ed);

                  for (int j = 0 ; j<ed ; j++){
                        int v;
                        scanf("%d",&v);

                        EDGE[{u,v}]++;
                        EDGE[{v,u}]++;

                        if (EDGE[{u,v}]==1){
                              G[u].push_back(v);
                              G[v].push_back(u);
                        }
                  }
            }
            for (int i=0 ; i<n;i++){
                  if (!Discovary[i]){
                        Bridge(i,-1);
                  }
            }
            if (!ans.empty())sort(ans.begin(),ans.end());

            printf("Case %d:\n",_t);
            printf("%d critical links\n",ans.size());

            for (int i=0;i<ans.size();i++)printf("%d - %d\n",ans[i].first,ans[i].second);

            clean();
      }

      return 0;
}
