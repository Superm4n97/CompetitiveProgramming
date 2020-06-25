#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,k;
            cin >> n >> k;
            string s;
            cin >> s;

            ll L[n+6] , R[n+6];

            ll cnt = 0 , ans = 0;

            if (s[0]=='0'){
                  ans = 1;
            }

            for (int i=1 ; i<n;i++){
                  if (s[i]=='0'){
                        cnt++;
                        if(cnt>k){
                              ans++;
                              cnt=0;
                        }
                  }
                  else {
                        if (cnt<k){
                              ans--;
                              if (ans<0)ans=0;
                        }
                        cnt=0;
                  }
            }
            cout << ans << endl;
      }

      return 0;
}
