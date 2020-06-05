#include<bits/stdc++.h>
#define ll long long int
#define maxn 505

using namespace std;

ll dp[37][maxn][maxn] , n;

ll rec(ll pos, ll current , ll pre)
{
      if (dp[pos][current][pre] != -1)return dp[pos][current][pre];

      if (current==0)dp[pos][current][pre] = 1;

      ll cnt = 0;

      for (int i=min(pre-1,current); i>0 ; i--){
            cnt += rec(pos+1 , current - i , i);
      }

      cout << " pos " << pos << "  - curr " << current << endl;

      return dp[pos][current][pre] = cnt;
}

int main()
{
      memset(dp,-1,sizeof dp);

      scanf("%lld",&n);

      printf("%lld\n",rec(0,n,505));


      return 0;
}
