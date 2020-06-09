#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll dp[maxn] , s[maxn] , D[maxn] , n , ans;

void clean()
{
      ans = 0;
      for (int i=0 ; i<=n+2;  i++){
            dp[i] = -1;
      }
}

ll rec(ll a)
{
      if (dp[a] != -1)return dp[a];

      if (a==1)return dp[a] = 1;
      if (D[a] == 0){
            if (s[1]<s[a])return dp[a] = 2;
            return dp[a] = 1;
      }

      ll res = 1;

      if (s[1]<s[a])res = 2;

      for (int i=2 ; i*i<=a ; i++){
            if (a%i == 0){
                  ll t1 = i , t2 = a/i;
                  if (s[t1]<s[a])res = max(rec(t1)+1 , res);
                  if (s[t2]<s[a])res = max(rec(t2)+1 , res);
            }
      }

      return dp[a] = res;
}

int main()
{
      for (ll i=2 ; i<maxn; i++){
            if (D[i]==0){
                  for (ll j = i*i ; j<maxn ; j+=i){
                        D[j] = 1;
                  }
            }
      }

      ll tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            for (int i=1 ; i<=n; i++)scanf("%I64d",&s[i]);

            clean();

            for (ll i = n ; i>=1 ; i--){
                  if (dp[i]==-1)ans = max(rec(i) , ans);
            }
            printf("%I64d\n",ans);
      }



      return 0;
}
