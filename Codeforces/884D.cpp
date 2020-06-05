#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin >> n ;
      vector < ll >  v;

      for (int i=0;i<n;i++){
            ll a;
            cin >> a;
            v.push_back(a);
      }
      sort(v.begin(),v.end());

      for (int i=1;i<n;i++)v[i] += v[i-1];

      if (n==1)cout << 0 << endl;
      else if (n==2 || n==3)cout << v[n-1] << endl;
      else {
            ll sum = 0;

            for (int i=n-1 ; i>=0 ; i-=2){
                  sum+=v[i];
                  if (i==2 || i==1)break;
            }
            cout << sum << endl;
      }

      return 0;
}
