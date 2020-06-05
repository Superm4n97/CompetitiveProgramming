#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[35] , n,m,A[35];

void clean()
{
      memset(dp,-1,sizeof dp);
}

ll rec(ll id)
{
      if (id==n){
            ll temp = A[id]%m;
            dp[id] = temp;
      }

      if (dp[id] != -1)return dp[id];

      ll res = A[id] % m;

      for (ll i = id + 1 ; i <= n ; i++){
            ll temp = rec(i)*A[id];
            temp %= m;

            res += temp;
            res %= m;
      }

      return dp[id] = res;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            clean();

            ll a;
            cin >> a >> m;

            ll i = 1 , j = 1;

            while(a){
                  A[j] = min(i,a);
                  a -= min(i,a);

                  i*=2;
                  j++;
            }
            n = j-1;
            ll ans = 0;

            for (int i=1 ; i<= n; i++){
                  ans += rec(i);
                  ans%=m;
            }
            cout << ans << endl;
      }


      return 0;
}
