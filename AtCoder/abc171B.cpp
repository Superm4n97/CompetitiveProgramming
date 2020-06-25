#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n , k;
      cin >> n >> k;

      vector < ll > v;

      for (int i=0 ; i<n;i++){
            ll a;
            cin >> a;

            v.push_back(a);
      }

      sort(v.begin(),v.end());

      ll ans = 0;

      for (int i=0 ; i<min(k,n) ; i++)ans+=v[i];

      cout << ans << endl;

      return 0;
}
