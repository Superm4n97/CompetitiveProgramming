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

#define maxn            1000006

using namespace std;

vector < ll > G[maxn] , P;
ll D[5][maxn];
ll n,m,_a,_b,_c;

void clean()
{
      for (int i=0;i<n+4 ; i++){
            G[i].clear();
            D[1][i] = D[2][i] = D[3][i] = inf;
      }
      P.clear();
}

void bfs(ll source, ll id)
{
      queue < ll > q;
      q.push(source);

      D[id][source] = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0;i<G[u].size();i++){
                  ll v = G[u][i];

                  if (D[id][v] > D[id][u]+1){
                        D[id][v] = D[id][u]+1;
                        q.push(v);
                  }
            }
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scanf("%I64d %I64d %I64d %I64d %I64d",&n,&m,&_a,&_b,&_c);

            clean();

            for (int i=0;i<m;i++){
                  ll a;
                  scanf("%I64d",&a);

                  P.push_back(a);
            }
            P.push_back(0LL);

            for (int i=0;i<m;i++){
                  ll a, b;
                  scll(a,b);

                  G[a].pb(b);
                  G[b].pb(a);
            }

            srt(P);
            for (int i=1 ; i<=m;i++)P[i] += P[i-1];

            bfs(_a,1);
            bfs(_b,2);
            bfs(_c,3);

            ll ans = inf;

            for (int i=1 ; i<=n ; i++){
                  ll t1 = D[1][i] , t2 = D[2][i] , t3 = D[3][i];
                  if (t1+t2+t3 > m)continue;


                  ll cost = P[t1+t2+t3]+P[t2];

                  ans = min(ans,cost);
            }

            printf("%I64d\n",ans);
      }




      return 0;
}
