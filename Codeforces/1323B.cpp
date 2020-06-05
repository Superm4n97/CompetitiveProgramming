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

#define maxn            40005

using namespace std;

vll divisors;
ll N[maxn] , M[maxn] , ans = 0;
ll cntN[maxn] , cntM[maxn] , n, m, k;

ll countN(ll id)
{
      if (id>n)return 0LL;
      else return cntN[id];
}

ll countM(ll id)
{
      if (id>m)return 0LL;
      else return cntM[id];
}

int main()
{
      cin >> n >> m >> k;

      for (int i=1 ; i<=n; i++){
            cin >> N[i];
            N[i] += N[i-1];
      }
      for (int i=1 ; i<=m; i++){
            cin >> M[i];
            M[i]+=M[i-1];
      }

      for (int i=1 ; i*i<=k ; i++){
            if (k%i==0){
                  if (i*i == k)divisors.pb(i);
                  else {
                        divisors.pb(i);
                        divisors.pb(k/i);
                  }
            }
      }

      for (int j=0 ; j<divisors.size() ; j++){
            ll D = divisors[j];

            if (D<=n){
                  ll cnt  = 0;
                  for (int i=D ; i<=n ; i++){
                        if (N[i] - N[i-D] == D)cnt++;
                  }
                  cntN[D] = cnt;
            }
            if (D<=m){
                  ll cnt = 0;
                  for (int i=D ; i<=m ;i++){
                        if (M[i] - M[i-D] == D)cnt++;
                  }
                  cntM[D] = cnt;
            }
      }

      for (int i=0; i<divisors.size() ; i++){
            ll a = divisors[i] , b = k/divisors[i];
            ans+=(countN(a) * countM(b));
      }
      cout << ans << endl;



      return 0;
}
