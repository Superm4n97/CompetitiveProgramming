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

ll a[10][10];
ll dp[10][10];

int main()
{
      ll k;
      cin >> k;
      ll aa = 262143 , bb = 131071 , cc =  131072;
      ll n= 2,m =3;

      a[1][1] = a[2][2]= aa;
      a[2][1] = cc;
      a[1][2] = a[2][3] = bb;
      a[1][3] = bb-k;

      cout << n << " " << m << endl;

      for (int i=1 ; i<=n; i++){
            for (int j = 1 ; j<=m; j++){
                  //dp[i][j] = max(dp[i-1][j]&a[i][j], dp[i][j-1]&a[i][j]);
                  cout << a[i][j] << " ";
            }
            cout << endl;
      }



      return 0;
}
