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

#define maxn            100005

using namespace std;

ll n, m , sum = 0;
ll A[maxn];
ll C[maxn];

int main()
{
      cin >> n >> m;

      for (int i=1;i<=m;i++){
            cin >> A[i];
            sum+=A[i];
      }

      bool ans = true;
      ll cellBaki  = n , lastcell = n;

      if (sum<n)ans = false;

      for (int i=m ; i>0 ; i--){

            ll allow = cellBaki - (i-1);

            allow = min(allow,A[i]);

            //show(allow);

            //if (cellBaki-allow >= i-1){
                  cellBaki-=allow;
                  lastcell = lastcell - allow+1;
                  C[i] = lastcell;
                  if (C[i]>n-A[i]+1)ans = false;
                  lastcell--;
            //}
      }

      if (!ans)cout << -1 << endl;
      else {
            for (int i=1;i<=m;i++){
                  cout << C[i] << " " ;
            }
            cout << endl;
      }




      return 0;
}
