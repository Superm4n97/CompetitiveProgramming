#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
ll n , A[maxn][30];

int main()
{
     cin >> s;

     n = s.size();

     for (int i=0;i<n;i++){
            for (int j = 0;j<29;j++){
                  A[i+1][j] = A[i][j];
            }
            A[i+1][s[i]-'a']++;
     }

     ll b = 0 , e = n-1 , ans = n;

     while(b<=e){
            ll mid = (b+e)/2;

            ll cnt[30] , tut = 0;
            memset(cnt,0,sizeof cnt);

            for (int i=mid ; i<=n ; i++){
                  tut++;

                  for (int j = 0 ; j<26 ; j++){
                        if (A[i][j] - A[i-mid][j] > 0)cnt[j]++;
                  }
            }

            bool temp = false;

            for (int i=0;i<27;i++){
                  if (tut == cnt[i])temp = true;
            }

            if (temp){
                  ans = min(ans,mid);
                  e = mid-1;
            }
            else b = mid+1;
     }

     cout << ans << endl;

      return 0;
}
