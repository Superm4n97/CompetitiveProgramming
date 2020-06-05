#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(a) scanf("%I64d",&a)
#define mod 1000000007
#define maxn 2000006

using namespace std;

vector < ll > prime;
ll vis[maxn] , F[maxn] , P2[maxn];

ll bigMod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a%mod;

      ll temp = bigMod(a,p/2);

      temp*=temp;
      temp%=mod;

      if (p%=2){
            temp*=a;
            temp%=mod;
      }

      return temp;
}

void build()
{
      P2[0] = 1;
      for (int i = 1 ; i<maxn-1 ; i++){
            P2[i] = P2[i-1]*2;
            P2[i] %= mod;
      }

      F[0] = 1;
      for (int i=1 ; i<maxn-1; i++){
            F[i] = F[i-1]*i;
            F[i]%=mod;
      }

      for (int i=2 ; i<10004 ; i++){
            if (!vis[i]){
                  prime.push_back(i);

                  for (int j = i ; j*j <= 10004 ; j+=i)vis[j] = 1;
            }
      }
}

ll nCr(ll n, ll r)
{
      if (n==r || r==0)return 1;
      if (r==1 || r==n-1)return n;

      ll res = F[n] * bigMod(F[n-r] , mod-2);
      res%=mod;

      res*=bigMod(F[r],mod-2);
      res%=mod;


      return res;
}

int main()
{
      build();

      ll tc;
      scl(tc);

      while(tc--){
            ll x,y;
            scl(x);
            scl(y);

            ll ans = 1;

            for (int i=0 ; prime[i]*prime[i] <= x ; i++){
                  ll cnt = 0;

                  while(x%prime[i]==0){
                        cnt++;
                        x/=prime[i];
                  }

                  if (cnt>0){
                        ans *= nCr(cnt+y-1, cnt);
                        ans %= mod;
                  }
            }


            if (x>1){
                  ans*=y;
                  ans%=mod;
            }


            ans *= P2[y-1];
            ans%=mod;

            printf("%I64d\n",ans);
      }

      return 0;
}
