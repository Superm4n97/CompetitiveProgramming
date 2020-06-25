#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a, b;
            cin >> a >> b;

            ll ans = 0;

            if (a>b)swap(a,b);
            if (a!=b){
                  ll x = min(a,b-a);
                  ans+=x;
                  a-=x;
                  b-=2*x;
            }

            ans+=(a/3)*2;
            a%=3;

            if (a==2)ans++;

            cout << ans << endl;

      }

      return 0;
}
