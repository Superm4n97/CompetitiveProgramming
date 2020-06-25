#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a,b,n , cnt = 0;
            cin >> a >> b >> n;

            while(true){
                  if (a<b)swap(a,b);
                  if (a>n)break;

                  if (a+b>n){
                        cnt++;
                        break;
                  }

                  b+=a;
                  cnt++;
            }
            cout << cnt << endl;
      }

      return 0;
}
