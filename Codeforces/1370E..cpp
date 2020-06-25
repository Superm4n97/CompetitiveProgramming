#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n , one = 0 , zero = 0;
vector < ll > v;

int main()
{
      cin >> n;
      string s,t;
      cin >> s >> t;

      for (int i=0 ; i<n;i++){
            if (s[i]!=t[i]){
                  ll temp = -1;
                  if (s[i]=='1')temp = 1;

                  if (temp==1)one++;
                  else zero++;

                  v.push_back(temp);
            }
      }

      if (one!=zero){
            cout << -1 << endl;
            return 0;
      }

      ll counter = 0 , ans = 0;
      map < ll, ll > mp;

      for (int i=0 ; i<v.size() ; i++){
            counter+=v[i];

            mp[counter]++;

            if (counter!=0 && mp[counter]==1){
                  ans++;
            }
      }
      cout << ans << endl;

      return 0;
}
