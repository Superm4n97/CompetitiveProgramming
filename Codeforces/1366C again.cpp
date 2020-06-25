#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,m;

            cin >> n >> m;
            ll dis[70] , total[70];
            memset(dis,0,sizeof dis);
            memset(total,0,sizeof total);

            for (ll i=0;i<n;i++){
                  for (ll j=0;j<m;j++){
                        ll a;
                        cin >> a;

                        if (i+j == m+n-2-i-j)continue;

                        ll level = min(i+j,m+n-2 - i - j);
                        dis[level]+=a;
                        total[level]++;
                  }
            }

            ll ans = 0;

            for (int i=0 ; i<m+n;i++){
                  ans+=min(dis[i] , total[i]-dis[i]);
            }
            cout << ans << endl;
      }

      return 0;
}
