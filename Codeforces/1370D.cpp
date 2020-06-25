#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 1000000009;

using namespace std;

ll n,k,A[maxn], mn = inf;

int main()
{
      cin >> n >> k;

      for (int i=1; i <= n; i++){
            cin >> A[i];
            mn = min(mn,A[i]);
      }

      if (k<=2){
            cout << mn << endl;
            return 0;
      }

      ll b = 0 , e = inf;
      ll ans = inf;

      while(b<=e){
            ll mid = (b+e)/2;
            vector < ll > v;

            for (int i=1 ; i<=n;i++){
                  if (A[i]<=mid)v.push_back(i);
            }

            if (v.empty()){
                  b = mid+1;
                  continue;
            }

            ll pre1 = -1 , pre2 = -1 , cnt1 = 0 , cnt2 = 0;
            ll mx1 = 0;
            ll mx2 = 0;
            ll mn1 = inf;
            ll mn2 = inf;

            for (int i=0 ; i<v.size() ; i++){
                  if (v[i]-pre1>=2){
                        cnt1++;
                        mn1 = min(mn1,v[i]);
                        mx1 = max(mx1,v[i]);
                        pre1 = v[i];
                  }
            }

            for (int i=1 ; i<v.size() ; i++){
                  if (v[i]-pre2>=2){
                        cnt2++;
                        mn2 = min(mn2,v[i]);
                        mx2 = max(mx2,v[i]);
                        pre2 = v[i];
                  }
            }

            bool solution = false;

            if (k%2){ ///K is odd
                  ll half = (k+1)/2;

                  if (cnt1>=half || cnt2>=half){
                        solution = true;
                  }

                  if (cnt1==half-1){
                        if (mn1!=1 && mx1!=n && mx1!=0)solution = true;
                  }

                  if (cnt2==half-1){
                        if (mn2!=1 && mx2!=n && mx2!=0)solution = true;
                  }
            }
            else { /// k is even
                  ll half = k/2;

                  if (cnt1>half || cnt2>half){
                        solution = true;
                  }
                  if (cnt1==half){
                        if (mx1!=0){
                              if (mx1!=n || mn1!=1)solution = true;
                        }
                  }
                  if (cnt2==half){
                        if (mx2!=0){
                              if (mx2!=n || mn2!=1)solution = true;
                        }
                  }
            }

            if (solution){
                  e = mid-1;
                  ans = min(mid,ans);
            }
            else b = mid+1;
      }
      cout << ans << endl;


      return 0;
}
