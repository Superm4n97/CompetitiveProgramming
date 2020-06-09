#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2000006

using namespace std;



int main()
{
      map < ll , ll > mp,p;
      ll n;

      bool solution = true;

      cin >> n;

      for (int i=0 ;i<n;i++){
            ll a,c;
            cin >> a >> c;
            if (p[c]==0){
                  p[c] = 1;
                  mp[c] = a;
            }
            else {
                  if (mp[c]>a)solution = false;
                  mp[c] = max(mp[c],a);
            }
      }
      cout << (solution?"YES":"NO") << endl;



      return 0;
}
