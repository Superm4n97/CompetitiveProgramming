#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005
#define inf 10000000000012

using namespace std;

ll n,k,d , D[maxn],IN[maxn],UN[maxn];
vector < ll > G[maxn],ans;
map < pair <ll , ll>  , ll > mp;
queue < pair < ll , ll > > q;

int main()
{
      cin >> n >> k >> d;

      for (int i=0;i<k;i++){
            ll a;
            cin >> a;

            if (UN[a])continue;

            q.push({a,0});
            D[a] = 1;
            UN[a] = 1;
      }

      for (int i=1 ; i<n ; i++){
            ll a, b;
            cin >> a >> b;

            mp[{a,b}] = i;
            mp[{b,a}] = i;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      while(!q.empty()){
            ll u = q.front().first , p = q.front().second;
            q.pop();

            for (int i=0 ; i<G[u].size();i++){
                  ll v = G[u][i];

                  if (v==p)continue;

                  if (!D[v]){
                        q.push({v,u});
                        D[v] = 1;
                  }
                  else {
                        ll id = mp[{u,v}];
                        if (!IN[id]){
                              IN[id] = 1;
                              ans.push_back(id);
                        }
                  }
            }
      }

      cout << ans.size() << endl;
      for (int i=0;i<ans.size();i++)cout << ans[i] << " ";


      return 0;
}
