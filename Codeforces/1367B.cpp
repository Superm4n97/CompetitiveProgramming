#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll A[n+5] , even = 0 , odd = 0;

            for (int i=0;i<n;i++){
                  cin >> A[i];

                  if (i%2 != A[i]%2){
                        if (i%2)odd++;
                        else even++;
                  }
            }
            if (even!=odd)cout << -1 << endl;
            else cout << even << endl;
      }

      return 0;
}
