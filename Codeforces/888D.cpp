#include<bits/stdc++.h>
#define ll long long int
#define maxn 1004
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[maxn][7];

ll rec(ll n, ll k)
{
      if (k==0) return 1;
      if (n<k || n<=1 || k<0) return 0LL;
      if (dp[n][k] != -1) return dp[n][k];

      return dp[n][k] = rec(n-1,k) + (n-1)*rec(n-2,k-2) + (n-1)*(rec(n-1,k-1)-rec(n-2,k-1));
}

int main()
{
      memset(dp,-1,sizeof dp);

      ll n, k;
      cin >>n >> k;

      ll sum = 0LL;


      for (int i=0 ; i<=k ; i++){
            sum+=rec(n,i);
      }
      cout << sum << endl;


      return 0;
}
