#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll D[maxn];

int main()
{
      for (ll i=2 ; i<maxn; i++){
            if (D[i]==0){
                  D[i] = i;
                  for (ll j = i*i ; j<maxn ; j+=i){
                        if (D[j]==0)D[j] = i;
                  }
            }
      }

      int tc;
      cin >> tc;

      while(tc--){
            ll n,k;
            cin >> n >> k;

            cout << n+D[n]+(k-1)*2 << endl;
      }


      return 0;
}

