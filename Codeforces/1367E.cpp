#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k , mp[30];
string s;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            memset(mp,0,sizeof mp);

            cin >> n >> k;
            cin >> s;

            for (int i=0 ; i<n;i++)mp[s[i]-'a']++;

            vector < ll > div;
            ll ans = 0;

            for (int i = 1 ; i<=k;i++)
                  if (k%i==0)
                        div.push_back(i);

            for (int j = 0 ; j<div.size() ; j++){

                  ll b = 1 , e = n , solution = 0;

                  while(b<=e){

                        ll  mid = (b+e)/2 , cnt = 0;

                        for (int i=0 ; i<27;i++)cnt+=mp[i]/mid;

                        if (cnt>=div[j]){

                              b = mid+1;
                              solution = max(solution,mid);
                        }
                        else e = mid-1;
                  }

                  ans = max(ans,solution*div[j]);
            }

            cout << ans << endl;
      }

      return 0;
}
