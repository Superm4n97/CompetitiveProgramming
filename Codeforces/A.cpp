#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define mod  1000000007
#define inf  1e16

using namespace std;

bool solution = false;
vector < ll > G[maxn];
ll A[maxn] , S[maxn] , n;

void dfs(ll u, ll p)
{
      if (S[u] == -1){
            ll tut = inf;

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  if (v!=p)tut = min(A[v] , tut);
            }
            if (tut == inf)S[u] =
      }
}

int main()
{
      cin >> n;
      for (int i=2;i<=n;i++){
            ll a;
            cin >> a;

            G[a].push_back(i);
            G[i].push_back(a);
      }

      for (int i=1 ; i<= n ;i++)cin >> S[i];

      dfs(1,0);


      return 0;
}

