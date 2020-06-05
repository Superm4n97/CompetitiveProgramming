#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll n,C[55] , A[55] , k;
ll dp[55][1005];

void clean()
{
      memset(dp,-1,sizeof dp);
}

ll sum(ll a, ll b)
{
      ll temp = a+b;
      temp%=100000007;

      return temp;
}

ll rec(ll pos, ll val)
{
      if (val==0)return dp[pos][val] = 1;
      if (pos>n)return 0;

      if (dp[pos][val] != -1)return dp[pos][val];

      ll cnt = 0;
      for (int i=0 ; i<=C[pos] ; i++){
            ll temp = i*A[pos];

            if (val-temp<0)break;

            cnt = sum(cnt,rec(pos+1,val-temp));
      }

      return dp[pos][val] = cnt;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ;_t<=tc ; _t++){
            clean();

            scanf("%lld %lld",&n,&k);

            for (int i=1;i<=n;i++)scanf("%lld",&A[i]);
            for (int i=1;i<=n;i++)scanf("%lld",&C[i]);

            printf("Case %d: %lld\n",_t,rec(1,k));
      }


      return 0;
}
