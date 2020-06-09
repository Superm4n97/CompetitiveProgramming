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

#define maxn            1000006

using namespace std;

int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
vector < string > G;
ll n,m , badpeople , goodpeople;
bool solution;

void clean()
{
      solution = true;
      G.clear();
      badpeople = goodpeople = 0;
}

bool checkSolution(ll x, ll y, char ch)
{
      for (int i=0 ; i<4; i++){
            ll p = x+del_x[i];
            ll q = y+del_y[i];

            if (p<n && p>=0 && q<m && q>=0){
                  if (ch=='B' && G[p][q]=='G')return false;
                  if (ch=='G' && G[p][q]=='B')return false;
                  if (ch=='B' && G[p][q]=='.')G[p][q] = '#';
            }
      }
      return true;
}

bool check(ll x, ll y)
{
      if (x<n && x>=0 && y<m && y>=0){
            if (G[x][y]=='#')return false;
            else return true;
      }
      return false;
}

ll dfs(ll x, ll y)
{

      ll ret = 0;
      if (G[x][y]=='G')ret = 1;
      G[x][y] = '#';

      for (int i=0 ; i<4;i++){
            ll p = x+del_x[i] , q = y+del_y[i];
            if (check(p,q)){
                  ret+=dfs(p,q);
            }
      }
      return ret;
}

int main()
{

      ll tc;
      cin >> tc;

      while(tc--){
            clean();

            cin >> n >> m;

            for (int i=0 ; i<n;i++){
                  string s;
                  cin >> s;
                  G.pb(s);
            }
            for (int i=0 ; i<n;i++){
                  for (int j = 0 ; j<m; j++){
                        /*show(i);
                        show(j);
                        show(G[i][j]);*/

                        if (G[i][j]=='B')badpeople++;
                        if (G[i][j]=='G')goodpeople++;

                        if (!checkSolution(i,j,G[i][j]))solution = false;
                  }
            }

//            cout << endl;
//            for (int i=0 ; i<n;i++)cout << G[i] << endl;

            if (goodpeople == 0)cout << "Yes" << endl;
            else if (!solution)cout << "No" << endl;
            else {
                  if (G[n-1][m-1]=='#')cout << "No" << endl;
                  else {
                        ll temp = dfs(n-1 , m-1);
                        //show(temp);
                        if (temp==goodpeople)cout << "Yes" << endl;
                        else cout << "No" << endl;
                  }
            }
      }



      return 0;
}
