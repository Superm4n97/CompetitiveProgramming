#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000000000016

using namespace std;

ll n,k, A[1005];

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ;_t++){
            scanf("%lld %lld",&n,&k);
            n++;

            for (int i=1;i<=n;i++)scanf("%lld",&A[i]);

            ll b = 0, e = 100000006 , ans = inf;

            while(b<=e){
                  ll mid = (b+e)/2 , cnt = 0 , sum = 0;

                  for (int i=1;i<=n ; i++){
                        if (A[i]>mid){
                              cnt = inf;
                              break;
                        }
                        if (sum+A[i]>mid){
                              sum = 0;
                              cnt++;
                        }
                        else sum+=A[i];
                  }

                  if (cnt <= k){
                        ans = min(ans,mid);
                        e = mid-1;
                  }
                  else b = mid+1;
            }
            printf("Case %d: %lld\n",_t,ans);
            for (int i=1;i<=n;i++){
                  if (A[i])
            }
      }


      return 0;
}
