#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

vector < ll > G[maxn];
ll n,m , node[maxn][28] , inDegree[maxn], ans = 0;
string s;
bool solution = true;

void marge(ll u, ll v)
{
      ll temp = s[v-1] - 'a';
      for (int i=0 ; i<27 ;i++){
            ll tut = 0;
            if (i==temp)tut = 1;

            node[v][i] = max(node[u][i]+tut , node[v][i]);
            ans = max(ans,node[v][i]);
      }
}

int main()
{
      cin >> n >> m;
      cin >> s;

      for (int i=1 ; i<=n ; i++){
            ll temp = s[i-1] - 'a';

            node[i][temp]++;
            ans = max(ans,node[i][temp]);
      }

      for (int i=0; i <m ;i++){
            ll a,b;
            cin >> a >> b;

            G[a].push_back(b);

            inDegree[b]++;
      }

      queue < ll > q;

      for (int i=1 ; i<=n; i++){
            if (inDegree[i] == 0)q.push(i);
      }

      ll cnt = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            cnt++;

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  marge(u,v);

                  inDegree[v]--;

                  if (inDegree[v] == 0)q.push(v);
            }
      }

      if (cnt!=n)cout << -1 << endl;
      else cout << ans << endl;

      return 0;
}
