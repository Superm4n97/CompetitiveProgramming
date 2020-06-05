#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << x << " : " << endl
#define mod 998244353

using namespace std;

ll n,m,l,r;

ll BigMod(ll a, ll p)
{
      if (p==1)return a%mod;

      ll temp = BigMod(a,p/2);
      temp*=temp;
      temp%=mod;

      if (p%2){
            temp*=a;
            temp%= mod;
      }

      return temp;
}

int main()
{
      cin >> n >> m >> l >> r;

      ll total = n*m , k = r-l+1;

      if (total%2)cout << BigMod(r-l+1,total);
      else {
            ll ans;

            if (k%2==0)ans = (BigMod(k,total)*BigMod(2,mod-2))%mod;
            else ans = ((BigMod(k,total)+1)*BigMod(2,mod-2)) % mod;

            cout << ans << endl;
      }


      return 0;
}
