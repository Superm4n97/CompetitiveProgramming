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

string s[50];
ll n;
bool dp[55][55];

bool check(int i, int j)
{

      if (i==n-1 || j==n-1)return true;
      if (dp[i][j+1] || dp[i+1][j])return true;
      return  false;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            memset(dp,false, sizeof dp);

            bool ans = true;

            for (int i = 0 ; i<n ; i++)cin >> s[i];

            for (int i=n-1 ; i>=0 ; i--){
                  for (int j=n-1 ; j>=0; j--){
                        if (s[i][j]=='1'){
                              if (check(i,j)==false)ans = false;
                              else {
                                    /*show(i);
                                    show(j);
                                    cout << endl;*/

                                    dp[i][j] = true;
                              }
                        }
                  }
            }
            if (ans)cout << "YES" << endl;
            else cout << "NO" << endl;
      }




      return 0;
}
