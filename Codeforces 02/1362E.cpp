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
#define mod 1000000007

using namespace std;

ll Multiplication(ll a, ll b)
{
      a *= b;
      ll temp = a/mod;
      temp *= mod;

      return a - temp;
}

ll bigMod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a % mod;

      ll temp = bigMod(a,p/2);

      temp = Multiplication(temp,temp);

      if (p%2)temp = Multiplication(temp,a);

      return temp;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n , p;
            scll(n,p);

            vector < ll > v;

            for (int i=0 ; i<n;i++){
                  ll a;
                  scl(a);
                  v.pb(a);
            }

            if (p==1){
                  printf("%I64d\n",n%2);
                  continue;
            }
            ll pre = 0 , cnt = 0;
            rsrt(v);

            for (int i=0 ; i<n;i++){
                  if (pre == 0){
                        pre = v[i];
                        cnt = 1;
                  }
                  else {
                        if (pre==v[i]){
                              cnt--;
                              if (cnt==0)pre = 0;
                        }
                        else {
                              ll temp = pre - v[i];
                              temp*=2;
                              cnt *= temp;
                              pre = v[i];
                              cnt--;
                        }
                  }
                  show(i);
                  show(pre);
                  show(cnt);
                  cout << endl;
            }
            if (cnt==0)cout << 0 << endl;
            else {

                  ll ans = bigMod(p,pre);
                  ans = Multiplication(ans,cnt);
                  printf("%I64d\n",ans);
            }
      }



      return 0;
}
