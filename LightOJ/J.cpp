#include<iostream>
#include<stdio.h>
#define ll long long int
#define maxn 1000006
#define mod 1000000000

using namespace std;

ll n , i , j;
ll dp[1000006];

ll add(ll a, ll b)
{
      a+=b;
      if (a>mod)a-=mod;

      return a;
}

int main()
{
      dp[0] = 1;

      scanf("%lld",&n);

      for (i=0 ; (1<<i) <= n ; i++){
            ll a = 1<<i;

            for (j = a ; j<=n ; j++){
                  dp[j] = add(dp[j] , dp[j-a]);
            }
      }

      printf("%lld\n",dp[n]);



      return 0;
}
