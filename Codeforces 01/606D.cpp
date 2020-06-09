#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

vector < pair < ll , pair < ll , ll > > > G;
vector < pair < ll , ll > > mst , nonMst;
ll n,m , maxCost[maxn];
bool solution = true;

int main()
{
      scanf("%I64d %I64d",&n,&m);

      for (int i=1 ; i<=m; i++){
            ll a, b;
            scanf("%I64d %I64d",&a,&b);

            if (b == 0)nonMst.push_back({a,i});
            else mst.push_back({a,i});
      }

      sort(mst.begin(),mst.end());
      if (!nonMst.empty()) sort(nonMst.begin(),nonMst.end());

      for (int i=0;i<n-1 ; i++){
            ll weight = mst[i].first , id = mst[i].second , a = 1 , b = i+2;
            G.push_back({id,{a,b}});

            maxCost[b] = weight;
      }

      ll currentNode = n , follower = 2 , used = 0;

      for (int i=nonMst.size()-1 ; i>=0 ; i--){
            ll weight = nonMst[i].first , id = nonMst[i].second , a,b;

            if (currentNode==2){
                  solution = false;
                  break;
            }

            if (weight>=maxCost[currentNode]){
                  G.push_back({id,{currentNode,follower}});
                  follower++;

                  used++;

                  if (follower==currentNode){
                        currentNode--;
                        follower = 2;
                  }
            }
            else {
                  i++;
                  currentNode--;
                  follower = 2;
            }
      }
      if (!solution)printf("-1\n");
      else {
            sort(G.begin(),G.end());
            for (int i=0;i<m;i++){
                  printf("%I64d %I64d\n",G[i].second.first , G[i].second.second);
            }
      }

      return 0;
}
