#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000010

using namespace std;

ll n,m;
ll dp[1004][1004];
string s,t;

void clean()
{
      memset(dp,-1,sizeof dp);
}

ll rec(ll posN, ll posM)
{
      if (posN==n || posM==m)return (n-posN)+(m-posM);

      if (dp[posN][posM] != -1) return dp[posN][posM];

      ll t1 = rec(posN+1,posM+1)+1;

      if (s[posN]==t[posM])t1--;

      ll t2 = rec(posN+1,posM)+1;
      ll t3 = rec(posN,posM+1)+1;

      return dp[posN][posM] = min(t1,min(t2,t3));
}

int main()
{
      while(cin >> n){
            if (n==0)s = "";
            else cin >> s;
            cin >> m;

            if (m==0)t = "";
            else cin >> t;

            clean();

            printf("%lld\n",rec(0,0));
      }


      return 0;
}
