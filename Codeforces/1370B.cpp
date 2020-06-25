#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >>n;

            vector < ll > E,O;

            for (int i=1 ; i<=2*n;i++){
                  ll a;
                  cin >> a;

                  if (a%2)O.push_back(i);
                  else E.push_back(i);
            }

            ll cnt = 0;

            for (int i=1; i<O.size() ; i+=2){
                  if (cnt==n-1)break;

                  cout << O[i-1] << " " << O[i] << endl;
                  cnt++;
            }
            for (int i=1;i<E.size();i+=2){
                  if (cnt==n-1)break;

                  cout << E[i-1] << " " << E[i] << endl;
                  cnt++;
            }
      }


      return 0;
}
