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

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            scl(n);

            ll A[n+5],B[n+5];
            ll T[n+5][3];

            for(int i=1 ; i<=n;i++)scanf("%I64d %I64d",&A[i],&B[i]);

            ll starter , adva = inf;

            for (int i =1 ; i<=n;i++){
                  T[i][1] = A[i];

                  if (i==1){
                        T[i][0] = max(A[i]-B[n],0LL);
                  }
                  else T[i][0] = max(A[i]- B[i-1],0LL);

                  ll temp = T[i][1] - T[i][0];

                  if (temp<adva){
                        adva = temp;
                        starter = i;
                  }
            }

            ll ans = 0;

            for (int i=1 ; i<=n;i++){
                  if (i==starter){
                       ans += T[i][1];
                  }
                  else {
                        ans += T[i][0];
                  }
            }
            printf("%I64d\n",ans);
      }



      return 0;
}
