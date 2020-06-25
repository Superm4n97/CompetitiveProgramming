#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,x,m;
            cin >> n >> x >> m;

            ll L = x, R = x;
            for (int i=0;  i<m;i++){
                  ll a, b;
                  cin >> a >> b;

                  if (a>R || b<L)continue;

                  L = min(a,L);
                  R = max(R,b);
            }
            cout << (R-L+1) << endl;

      }


      return 0;
}
