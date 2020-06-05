#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll A[1505];

int main()
{
      ll n;
      cin >> n;
      for (int i=1 ; i<=n; i++)cin >> A[i];

      ll cnt = 0;

      for (int i=1 ; i<=n;i++){
            for (int j=i+1 ; j<=n;j++){
                 if (A[j] < A[i])cnt++;
            }
      }

      cnt%=2;

      ll m;
      cin >> m;

      for (int i=0 ; i<m ; i++){
            ll l,  r;
            cin >> l >> r;

            ll len = r-l+1;

            len = len * (len-1) / 2;

            if (len%2)cnt = 1 - cnt;

            cout << (cnt?"odd":"even") << endl;
      }

      return 0;
}
