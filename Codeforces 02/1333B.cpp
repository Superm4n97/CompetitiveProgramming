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
            cin >> n;

            ll A[n+5] , B[n+5] , T[n+5][5];
            memset(T,0,sizeof T);

            for (int i=1;i<=n;i++){
                  cin >> A[i];
            }
            for (int i=1 ; i<=n ; i++)cin >> B[i];

            for (int i=2;i<=n;i++){
                  T[i][0] = T[i-1][0];
                  T[i][1] = T[i-1][1];
                  T[i][2] = T[i-1][2];

                  if (A[i-1] == -1)T[i][0] = 1;
                  if (A[i-1] == 0)T[i][1] = 1;
                  if (A[i-1] == 1)T[i][2] = 1;
            }

            bool ans = true;

            for (int i=n; i>=1 ; i--){
                  if (B[i]>A[i] && T[i][2]==0)ans = false;
                  if (B[i]<A[i] && T[i][0]==0)ans = false;
            }

            cout << (ans ?"YES":"NO") << endl;
      }




      return 0;
}
