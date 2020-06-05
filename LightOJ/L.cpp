#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 1000006
#define inf 10000000000000016

using namespace std;

ll n,m,A[15];
ll dp[15][15];

void clean()
{
      memset(dp,-1,sizeof dp);
}

ll rec(ll pos, ll currentDigit)
{
      if (pos==n)return 1;

      if (dp[pos][currentDigit] != -1)return dp[pos][currentDigit];

      ll cnt = 0;

      for (int i=1;i<=m;i++){
            if (abs(currentDigit-A[i])<=2)cnt += rec(pos+1,A[i]);
      }

      return dp[pos][currentDigit] = cnt;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            clean();

            scanf("%lld %lld",&m,&n);

            for (int i=1;i<=m;i++)scanf("%lld",&A[i]);

            ll ans = 0;

            for (int i=1;i<=m;i++)ans += rec(1,A[i]);


            printf("Case %d: %lld\n",_t,ans);
      }



      return 0;
}
