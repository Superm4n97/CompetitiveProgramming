#include<bits/stdc++.h>
#define ll long long int
#define maxn 2005
#define mod 1000000007
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll DP[maxn][3LL][maxn];
ll m,d , A[maxn] , n;

ll dynamicProgramming(ll pos, ll lessThan , ll modulous)
{
      if (DP[pos][lessThan][modulous] != -1) return DP[pos][lessThan][modulous];

      if (pos==n){
            if (modulous==0)return DP[pos][lessThan][modulous] = 1LL;
            else return DP[pos][lessThan][modulous] = 0LL   ;
      }

      if (pos%2){
            if (lessThan){
                  ll temp = modulous*10 + d;
                  temp %= m;

                  return DP[pos][lessThan][modulous] = dynamicProgramming(pos+1 ,lessThan , temp);
            }
            else {
                  if (A[pos+1] < d)return DP[pos][lessThan][modulous] = 0LL;
                  else {
                        ll temp = modulous*10 + d , tut = 0;
                        temp %= m;

                        if (A[pos+1] > d) tut = 1;

                        return DP[pos][lessThan][modulous] = dynamicProgramming(pos+1,tut,temp);
                  }
            }
      }
      else {
            ll cnt = 0;

            if (lessThan){
                  for (int i=0;i<=9 ; i++){
                        if (i==d)continue;

                        ll temp = modulous*10 + i;
                        temp %= m;

                        cnt += dynamicProgramming(pos+1,lessThan,temp);
                        cnt%=mod;
                  }
            }
            else {
                  for (int i=0 ; i<=A[pos+1] ; i++){
                        if (i==d)continue;

                        ll temp = modulous*10 + i , tut = 1LL;
                        temp %= m;

                        if (i==A[pos+1])tut = 0LL;

                        cnt += dynamicProgramming(pos+1,tut,temp);
                        cnt %= mod;
                  }
            }

            return DP[pos][lessThan][modulous] = cnt;
      }
}

ll solve()
{
      memset(DP,-1,sizeof DP);

      ll ans = 0LL;

      //show(A[1]);

      for (int i=1 ; i <= A[1] ; i++){

            if (i==d)continue;

            ll tut = 1 , temp = i%m;
            if (A[1]==i)tut = 0LL;

            ans += dynamicProgramming(1LL,tut,temp);
            ans %= mod;
      }

      return ans;
}

bool check()
{
      for (int i = 2 ; i <= n ; i+=2){
            if (A[i] != d)return false;
      }
      for (int i=1 ; i<= n ; i+=2){
            if (A[i] == d)return false;
      }
      ll divisibility = 0;

      for (int i=1 ; i<=n; i++){
            divisibility*=10;
            divisibility+=A[i];
            divisibility %= m;
      }
      if (divisibility)return false;

      return true;
}

int main()
{
      cin >> m >> d;

      string s;
      cin >> s;

      n = s.size();

      for (int i=0;i<n ;i++)A[i+1] = s[i] - '0';

      ll t1 = solve();

      if (check())t1--;

      //show(t1);

      cin >> s;

      for (int i=0 ; i<n ; i++)A[i+1] = s[i] - '0';

      ll t2 = solve();

      ll tut = t2 - t1;
      if (tut<0)tut+=mod;

      cout << tut << endl;


      return 0;
}
