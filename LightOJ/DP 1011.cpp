#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll dp[20][66000] , A[20][20] , n;

void clean()
{
      memset(dp,-1,sizeof dp);
      memset(A,0,sizeof A);
      return;
}

ll rec(ll pos, ll mask)
{
      if (pos>=n)return 0;

      if (dp[pos][mask]!=-1)return dp[pos][mask];

      ll mx = 0;
      for (int i=0;i<n;i++){
            if (!(mask&(1 << i))){
                  mx = max(mx,rec(pos+1,mask|(1<<i))+A[pos][i]);
            }
      }

      return dp[pos][mask] = mx;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            clean();

            scanf("%lld",&n);

            ll mx = 0;

            for (int i=0;i<n;i++){
                  for (int j= 0 ;j<n;j++)scanf("%lld",&A[i][j]);
            }

            printf("Case %d: %lld\n",_t,rec(0,0));
      }

      return 0;
}
