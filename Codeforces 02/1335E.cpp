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

ll n;
vector < ll > G[205];

ll binarySearch(ll a , ll u)
{
      if (G[u].empty())return 0;
      ll b = 0 , e = G[u].size()-1 , res = -1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (G[u][mid] <= a){
                  res = max(res,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }

      return res+1;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            scanf("%I64d",&n);


            for (int i=1;i<=n;i++){
                  ll a;
                  scanf("%I64d",&a);
                  G[a].pb(i);
            }

            ll ans = 1;

            for (int i=1;i<201 ; i++){
                  if (G[i].empty())continue;

                  ll x = 0, y = G[i].size()-1;

                  while(x<y){

                        ll aa = 2*(x+1);

                        for (int j=1;j<201;j++){
                              ll bb;

                              ll t1 = binarySearch(G[i][x], j) , t2 = binarySearch(G[i][y]-1,j) ;
                              bb = t2 - t1;

                              ans = max(ans,aa+bb);

//                              show(ans);
//                              show(i);
//                              show(j);
                        }

                        x++;
                        y--;
                  }
            }

            printf("%I64d\n",ans);
            for (int i=0;i<=203;i++)G[i].clear();
      }




      return 0;
}
