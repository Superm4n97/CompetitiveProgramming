#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll k , A[15] , dp[12][102][102][3] , n;

ll DP(ll pos , ll modulo , ll sod , ll lessThan)
{
      if (dp[pos][modulo][sod][lessThan] != -1)return dp[pos][modulo][sod][lessThan];

      if (pos==n){
            if (sod==0 && modulo==0)return dp[pos][modulo][sod][lessThan] = 1;
            else return dp[pos][modulo][sod][lessThan] = 0;
      }

      ll r = 9 , tut = 1;
      if (!lessThan)r = A[pos+1];

      ll cnt = 0;

      for (ll i=0 ; i<=r ; i++){
            if (i==r && !lessThan) tut = 0;

            ll md = modulo*10+i, sd = sod+i;
            md%=k;
            sd%=k;


            cnt += DP(pos+1,md,sd,tut);
      }
      return dp[pos][modulo][sod][lessThan] = cnt;
}

ll solve(ll a)
{
      if (a==0)return 1;
      memset(dp,-1,sizeof dp);

      vector < ll > v;
      n = 0;

      while(a){
            n++;
            v.push_back(a%10);
            a/=10;
      }

      if(!v.empty())reverse(v.begin() , v.end());

      for (int i=1 ; i<=n ; i++)A[i] = v[i-1];

      ll ans = 0;

      for (ll i=0;i<=A[1] ; i++){
            ll temp1 = i%k , lss = 1;

            if (i==A[1])lss = 0;

            ans+=DP(1,temp1,temp1,lss);
//            show(i);
//            show(ans);
      }
      return ans;
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t <= tc ; _t++){
            ll a, b;
            scanf("%lld %lld %lld",&a, &b, &k);

            if (k>100){
                  printf("Case %d: 0\n",_t);
                  continue;
            }

            ll t1 = solve(a-1);

            //show(t1);

            ll t2 = solve(b);

            printf("Case %d: %lld\n",_t,t2-t1);
      }


      return 0;
}
