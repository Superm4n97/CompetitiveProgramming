#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 1000000009

using namespace std;

ll n,k,A[maxn];

int main()
{
      cin >> n >> k;
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      ll b = 0, e = inf , ans = inf;

      while(b<=e){
            ll mid = (b+e)/2;
            ll x1 = 0 , x2 = 1 , cnt1 = 0 , cnt2 = 0;

            for (int i=1 ; i<=n ; i++){
                  if (!x1){ /// 0 means even position
                        if (A[i]<=mid){
                              x1 = 1;
                              cnt1++;
                        }
                  }
                  else {
                        x1 = 0;
                        cnt1++;
                  }

                  if (!x2){
                        if (A[i]<=mid){
                              x2 = 1;
                              cnt2++;
                        }
                  }
                  else {
                        x2 = 0;
                        cnt2++;
                  }
            }

            if (cnt1>=k || cnt2>=k){
                  e = mid-1;
                  ans = min(ans,mid);
            }
            else {
                  b = mid+1;
            }
      }
      cout << ans << endl;

      return 0;
}
