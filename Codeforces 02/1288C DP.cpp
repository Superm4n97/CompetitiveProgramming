#include<bits/stdc++.h>
#define ll long long int
#define maxn 1005
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll n,m , dp[maxn][maxn];

ll rec(ll pos, ll pre)
{
      if (dp[pos][pre] != -1)return dp[pos][pre];
      if (pos == m)return dp[pos][pre] = pre;

      ll cnt = 0;
      for (int i=1 ; i<= pre ; i++){
            cnt+=rec(pos+1,i);
            cnt %= mod;
      }
      return dp[pos][pre] = cnt;
}

int main()
{
      memset(dp,-1,sizeof dp);
      cin >> n >> m;
      m*=2;
      cout << rec(1,n) << endl;

      return 0;
}
