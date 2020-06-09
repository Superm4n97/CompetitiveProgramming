#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair
#define inf8            100000008

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;
            ll n = s.size();

            ll leftZero[n+5] , leftOne[n+5] , rightZero[n+5] , rightOne[n+5];

            memset(leftZero,0,sizeof leftZero);
            memset(leftOne,0,sizeof leftOne);
            memset(rightOne,0,sizeof rightOne);
            memset(rightZero,0,sizeof rightZero);

            for (int i=1 ; i<=n; i++){
                  leftOne[i] = leftOne[i-1];
                  leftZero[i] = leftZero[i-1];

                  if (s[i-1]=='1')leftOne[i]++;
                  else leftZero[i]++;
            }
            for (int i=n ; i>=1 ; i--){
                  rightOne[i] = rightOne[i+1];
                  rightZero[i] = rightZero[i+1];

                  if (s[i-1]=='1')rightOne[i]++;
                  else rightZero[i]++;
            }

            ll ans = min(leftOne[n],leftZero[n]);

            for (int i=1 ; i<=n ; i++){
                  ll t1 = leftOne[i]+rightZero[i+1];
                  ll t2 = leftZero[i]+rightOne[i+1];
                  ans = min(ans,min(t1,t2));
            }
            cout << ans << endl;

      }


    return 0;
}
