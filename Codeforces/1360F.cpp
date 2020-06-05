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

int dp[13][1050] , n,m;
string s[14];
vector < char > ans;

int rec(int pos , int mask)
{
      if (pos==m)return 1;
      if (dp[pos][mask] != -1) return dp[pos][mask];

      for (char j = 'a' ; j<='z' ; j++){
            int tut = mask;

            bool possible = true;

            for (int i=0 ; i<n; i++){
                  if (s[i][pos] != j){
                        int temp = 1<<i;

                        if (temp&tut){
                              possible = false;
                              break;
                        }
                        else {
                              tut |= temp;
                        }
                  }
            }

            if (possible && rec(pos+1,tut)){
                  ans.push_back(j);
                  return dp[pos][mask] = 1;
            }
      }

      return dp[pos][mask] = 0;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            memset(dp,-1,sizeof dp);
            ans.clear();

            cin >> n >> m;

            for (int i=0 ; i<n;i++)cin >> s[i];

            for (char j = 'a' ; j<='z' ; j++){
                  int tut = 0;

                  for (int i=0 ; i<n ; i++){
                        if (s[i][0] != j){
                              int temp = 1<<i;
                              tut |= temp;
                        }
                  }
                  if (rec(1,tut)){
                        ans.pb(j);
                        break;
                  }
            }

            if (ans.size()==m){
                  for (int i=ans.size()-1 ; i>=0 ; i--)cout << ans[i];
                  cout << endl;
            }
            else cout << -1 << endl;
      }



      return 0;
}
