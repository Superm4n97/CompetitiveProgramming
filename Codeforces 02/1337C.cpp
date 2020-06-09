#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            200005

using namespace std;

ll n,k , ans = 0;
vll G[maxn];
ll P[maxn] , vis[maxn] , L[maxn] , M[maxn];

void dfs(ll u)
{
      for (int i=0;i<G[u].size();i++){
            ll v = G[u][i];

            if (vis[v]==0){
                  P[v] = u;
                  vis[v] = 1;
                  L[v] = L[u]+1;

                  dfs(v);
            }
      }
}

int main()
{
      cin >> n >> k;

      for (int i=1;i<n;i++){
            ll a, b;
            cin >> a >> b;

            G[a].pb(b);
            G[b].pb(a);
      }

      vis[1] = 1;
      P[1] = 1;
      L[1] = 0;

      dfs(1);

      priority_queue < pll > pq;

      for (int i=1;i<=n;i++){
            pq.push({L[i] , i});
      }

      ll sum = 0;

      while(k){
            ll depth = pq.top().first , u = pq.top().second;
            pq.pop();

            if (L[u] != depth){
                  depth = L[u];

                  ll v = P[u];
                  M[v] += (M[u]+1);
                  L[v] -= (M[u]+1);

                  pq.push({depth,u});
                  continue;
            }

            ans += depth;

//            show(depth);
//            show(u);

            ll v = P[u];

            k--;

            if (M[u]==0){
                  M[v] += M[u]+1;
                  L[v] -= (M[u]+1);
            }
      }

      //for (int i=1 ; i<=n;i++)cout << i << " " << P[i] << endl;

      cout << ans << endl;



      return 0;
}
