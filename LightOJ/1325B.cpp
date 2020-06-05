#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            vector < ll > v;

            for (int i=0;i<n;i++){
                  ll a;
                  cin >> a;

                  v.push_back(a);
            }

            sort(v.begin(),v.end());

            ll cnt = 1;

            for (int i=1;i<n;i++){
                  if (v[i]!=v[i-1])cnt++;
            }

            cout << cnt << endl;
      }

      return 0;
}
