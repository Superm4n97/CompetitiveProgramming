#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

vector < ll > G[maxn];
vector < pair < ll, ll > > C;
ll n,m , cost[maxn] , value[maxn];

int main()
{
      cin >> n >> m ;
      for (int i=1 ; i<=n;i++){

            cin >> value[i];
            C.push_back({value[i],i});
      }
      sort(C.rbegin(),C.rend());

      for (int i=0 ; i<m;i++){

            ll a,b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);

            cost[a]+=value[b];
            cost[b]+=value[a];
      }

      ll ans = 0;

      for (int i = 0;i<n;i++){

            ll node = C[i].second;
            ans+=cost[node];

            for (int j = 0;j<G[node].size() ; j++){

                  ll child = G[node][j];
                  cost[child]-=value[node];
            }
      }

      cout << ans << endl;



      return 0;
}
