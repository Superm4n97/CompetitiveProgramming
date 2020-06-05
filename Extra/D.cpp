#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 10056

using namespace std;

ll C[1005][1005];
ll dp[1005];

ll combine(ll a, ll b)
{
      a+=b;
      if (a >= mod)a-=mod;

      return a;
}

ll mul(ll a, ll b)
{
      a*=b;
      a%=mod;

      return a;
}

ll nCr(ll n, ll r)
{
      if (n<r) return 0;
      if (n==r || r==0)return 1;
      if (r==1)return n;

      if (C[n][r] != -1)return C[n][r];

      ll t1 = nCr(n-1,r) , t2 = nCr(n-1,r-1);

      return C[n][r] = combine(t1,t2);
}

ll rec(ll n)
{
      if (n==0)return 1;

      if (dp[n] != -1)return dp[n];

      ll ans = 0;

      for (int i=1;i<=n;i++){
            ans = combine(ans, mul(nCr(n,i),rec(n-i)));
      }

      return dp[n] = ans;
}

int main()
{
      memset(C,-1,sizeof C);
      memset(dp,-1,sizeof dp);

      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            scanf("%lld",&n);

            printf("Case %d: %lld\n",_t,);
      }


      return 0;
}

