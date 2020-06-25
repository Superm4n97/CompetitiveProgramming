#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin>> n;

      map < ll ,ll > mp;
      ll sum = 0;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;

            mp[a]++;
            sum+=a;
      }

      ll q;
      cin >> q;

      while(q--){
            ll b,c;
            cin >> b >> c;

            ll cnt = mp[b];

            mp[c]+=cnt;
            mp[b] = 0;

            sum-=cnt*b;
            sum+=cnt*c;

            cout << sum << endl;
      }

      return 0;
}

