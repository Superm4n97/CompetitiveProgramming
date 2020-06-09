#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005

using namespace std;

/*
dp[N][5]
rec(u,dis,p)
      if dis==1 then go to next child
      if dis==2 then it can be dis = 1 or go to next child
      if dis==3
            if u is leaf node then it must be connected by an edge
            else dis can be 1 or go to next child
      if dis==4 then it must be connected by an edge
*/

ll n , dp[maxn][6];
vector < ll > G[maxn];

ll rec(ll u, ll dis, ll p)
{
      if (dp[u][dis] != -1)return dp[u][dis];

      ll ret = 0;

      if (dis==1){
            for (int i=0;i<G[u].size() ; i++){
                  ll v = G[u][i];

                  if (v!=p)ret+=rec(v,2,u);
            }
      }
      else if (dis==2){
            ll t1 = 1 , t2 = 0; // t1 (if I connect the current vertex to root), t2 (if I don't)
            for (int i=0 ; i<G[u].size();i++){
                  ll v = G[u][i];
                  if (v != p){
                        t1+=rec(v,2,u);
                        t2+=rec(v,3,u);
                  }
            }
            ret = min(t1,t2);
      }
      else if (dis==3){
            if (G[u].size()==1)ret = 1;
            else {
                  ll t1 = 1 , t2 = 0;// t1 (if I connect the current vertex to root), t2 (if I don't)
                  for (int i=0 ; i<G[u].size() ; i++){
                        ll v = G[u][i];
                        if (v!=p){
                              t1 += rec(v,2,u);
                              t2 += rec(v,4,u);
                        }
                  }
                  ret = min(t1,t2);
            }
      }
      else {
            ret = 1;
            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  if (v!=p){
                        ret += rec(v,2,u);
                  }
            }
      }
      return dp[u][dis] = ret;
}

int main()
{
      memset(dp,-1,sizeof dp);

      cin >> n;
      for (int i=1; i<n;i++){
            ll a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
      }

      ll ans = 0;

      for (int i=0;i<G[1].size(); i++){
            ll v = G[1][i];
            ans += rec(v,1,1);
      }

      cout << ans << endl;

      return 0;
}
