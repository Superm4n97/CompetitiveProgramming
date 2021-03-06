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
///4direction ->
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1005

using namespace std;

int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
ll n,m , vis[maxn][maxn] , ans = 0;
string s[maxn];
bool solution = true;

bool check(ll x, ll y)
{
      if (x>=0 && y>=0 && x<n && y<m && s[x][y]=='#' && vis[x][y]==0)return true;
      return false;
}

void dfs(ll x, ll y)
{
      vis[x][y] = 1;

      for (int i=0 ; i<4 ; i++){
            ll p = x+del_x[i] , q = y+del_y[i];

            if (check(p,q))dfs(p,q);
      }
}

int main()
{
      cin >> n >> m;

      for (int i=0 ; i<n ; i++){
            cin >> s[i];
      }

      ll column = 0 , row = 0;

      for (int i=0 ; i<n;i++){
            ll cnt = 0;
            if (s[i][0] == '#')cnt = 1;

            for (int j = 1 ; j <m ; j++){
                  if (s[i][j-1] == '.' && s[i][j] == '#')cnt++;
            }
            if (cnt>1)solution = false ;
            if (cnt==1) row++;
      }

      for (int j = 0 ; j<m ; j++){
            ll cnt = 0;
            if (s[0][j] == '#')cnt  = 1;

            for (int i = 1 ; i<n;i++){
                  if (s[i-1][j]=='.' && s[i][j]=='#')cnt++;
            }

            if (cnt>1)solution = false;
            if (cnt==1)column++;
      }

      if ((row==n && column!=m) || (row!=n && column==m))solution = false;

//      show(row);
//      show(column);

      if (!solution){
            cout << -1 << endl;
      }
      else {
            for (int i=0 ; i<n ; i++){
                  for (int j= 0 ;j<m ; j++){
                        if (check(i,j))dfs(i,j) , ans++;
                  }
            }
            cout << ans << endl;
      }




      return 0;
}
