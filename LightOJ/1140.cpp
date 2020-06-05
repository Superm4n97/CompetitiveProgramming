#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll n , dp[13][11][3][2][13] , A[13];

ll dynamicProgramming(ll pos , ll digit , ll lessThan, ll continuous , ll extra)
{
      if (dp[pos][digit][lessThan][continuous][extra] != -1)return dp[pos][digit][lessThan][continuous][extra];
      if (pos==n){
            if (!digit)return dp[pos][digit][lessThan][continuous][extra] = extra+1;
            else return dp[pos][digit][lessThan][continuous][extra] = extra;
            //return dp[pos][digit][lessThan][continuous][extra] = extra;
      }

      ll r = 9 , tut = 1 , ex = extra;
      if (!lessThan)r = A[pos+1];

      ll cnt = 0 , con = 1;

      for (int i=0 ; i<=r ; i++){
            if (!lessThan && i==r)tut = 0;

            if (!digit && continuous)ex++;

            if (!continuous && i==0)con = 0;
            else con = 1;

            cnt += dynamicProgramming(pos+1 ,i ,tut ,con,ex);
      }

      return dp[pos][digit][lessThan][continuous][extra] = cnt;
}

ll solve(ll a)
{
      if (a==-1)return 0;
      if (a==0)return 1;

      memset(dp,-1,sizeof dp);

      n = 0;
      vector < ll > v;
      while(a){
            n++;
            v.push_back(a%10);
            a/=10;
      }
      if (!v.empty())reverse(v.begin(),v.end());

      for (int i=0 ; i<n;i++)A[i+1] = v[i];

      ll ans = 0 , con = 0 , ls = 1;

      for (int i=0;i<=A[1];i++){
            if (i>0)con = 1;
            if (i==A[1])ls = 0;
            ans += dynamicProgramming(1,i,ls,con,0);
      }

      return ans;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            ll t1 = solve(a-1);
            show(t1);
            ll t2 = solve(b);
            show(t2);

            cout << "  " << t2 - t1 << endl;
      }


      return 0;
}
