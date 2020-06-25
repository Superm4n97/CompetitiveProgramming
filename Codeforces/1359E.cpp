#include<bits/stdc++.h>
#define ll long long int
#define mod 998244353
#define maxn 500005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[maxn] , F[maxn] , n,k;

ll normal(ll a)
{
      ll temp =  a/mod;
      return a - temp*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a;

      ll temp = bigmod(a,p/2);
      temp = normal(temp*temp);

      if (p%2)temp = normal(temp*a);

      return temp;
}

ll inverse(ll a)
{
      return bigmod(a,mod-2);
}

ll C(ll n, ll r)
{
      if (r>n)return 0;

      ll temp = normal(F[r]*F[n-r]);

      return normal(F[n]*inverse(temp));
}

int main()
{
      F[0] = 1;

      for (int i=1 ; i<maxn ; i++){

            F[i] = F[i-1]*i;
            F[i]%=mod;
      }

      scanf("%I64d %I64d",&n,&k);
      ll ans = 0;

      for (int i=1 ; i<=n;i++){

            ll temp = n / i - 1;
            ans = normal(ans+C(temp,k-1));
      }

      cout << ans << endl;


      return 0;
}
