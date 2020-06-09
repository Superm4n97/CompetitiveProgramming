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

ll n,x ,d[maxn] , h[maxn] , c[maxn];

ll sum(ll a)
{
      return a*(a+1)/2;
}

int main()
{
      cin >> n >> x;

      for (int i=1 ; i<=n;i++){
            cin >> d[i];
            c[i] = c[i-1]+d[i];
            h[i] = sum(d[i]);
            h[i]+=h[i-1];
      }
      for (int i=n+1;i<=2*n ; i++){
            d[i] = d[i-n];

            c[i] = c[i-1]+d[i];
            h[i] = sum(d[i]);
            h[i]+=h[i-1];
      }

      ll b = 1 , e = 1 , ans = 0;

      while(e<=2*n)
      {
            ll days = c[e] - c[b-1];

//            show(e);
//            show(b);
//            show(c[e]);
//            cout << endl;

            while(true){
                  if (days - d[b] >= x){
                        days-=d[b];
                        b++;
                  }
                  else break;
            }

            ans = max(ans,h[e]-h[b-1] - sum(max(0LL,days-x)));

            e++;
      }
      cout << ans << endl;



      return 0;
}
