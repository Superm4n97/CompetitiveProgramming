#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k;
ll dp[10004] , A[105];

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ;_t<=tc ; _t++){
            memset(dp,0,sizeof dp);

            scanf("%lld %lld",&n, &k);

            for (int i=1 ; i<=n;i++)scanf("%lld",&A[i]);

            dp[0] = 1;

            for (int i=1;i<=n;i++){
                  for (int j=A[i];j<=k;j++){
                        dp[j] = (dp[j] + dp[j-A[i]])%100000007;
                  }
            }
            printf("Case %d: %lld\n",_t,dp[k]);
      }


      return 0;
}
