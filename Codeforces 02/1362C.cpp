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
#define inf             1000000000000000005

#define maxn            1000006

using namespace std;

ll P[70];


int main()
{
      //cout << 4000000000162 - 3999999999987 << endl;
      //show(inf);
      P[0] = 1;
      for (ll i=1 ; i<=63 ; i++){
            P[i] = P[i-1]*2;
            if (P[i]>inf)break;
      }

      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            scl(n);
            ll ans = 0 , tut = 2;

            for (ll i=1; ;i++){
                  if (P[i-1]>n)break;
                  ll temp = n - P[i-1];



                  temp/=tut;
                  temp++;
                  //show(temp);
                  ans+=(temp*i);

                  tut*=2;
            }
            //show(ans);
            cout << ans << endl;
      }




      return 0;
}
