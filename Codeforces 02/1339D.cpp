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

#define maxn            300005

using namespace std;

ll n , cnt[maxn] , L[maxn] , occur[maxn];
vector < ll > G[maxn] , child;

void bfs(ll sour)
{
      L[sour] = 0;
      queue < ll > q;

      q.push(sour);

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0;i<G[u].size();i++){
                  ll v = G[u][i];

                  if (L[v]==-1){
                        L[v] = L[u]+1;
                        q.push(v);
                  }
            }
      }
}

int main()
{
      memset(L,-1,sizeof L);

      cin >> n;

      for (int i=1;i<n;i++){
            ll a,b;
            cin >>  a >> b;

            cnt[a]++;
            cnt[b]++;

            G[a].pb(b);
            G[b].pb(a);
      }

      for (int i=1; i<=n;i++){
            if (cnt[i]==1)child.pb(i);
      }

     bfs(child[0]);

     ll mn = 1 , mx = n-1;

     for (int i=0;i<child.size();i++){
            occur[G[child[i]][0]]++;

            if (L[child[i]] % 2){
                  mn = 3;
            }
     }

     for (int i=1 ; i<=n;i++){
            if (occur[i]>1){
                  ll temp = occur[i]-1;
                  mx-=temp;
            }
     }
     cout << mn <<" " << mx << endl;




      return 0;
}
