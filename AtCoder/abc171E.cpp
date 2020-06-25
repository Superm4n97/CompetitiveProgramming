#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n,sum = 0;
      cin >> n;
      vector < ll > v;

      for (int i=0 ; i<n;i++){

            ll a;
            cin >> a;
            v.push_back(a);

            sum^=a;
      }
      for (int i = 0 ; i<n;i++){
            cout << (sum^v[i]) << " ";
      }
      cout << endl;

      return 0;
}
