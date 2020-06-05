#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 1000006
#define inf 10000000000000016

using namespace std;

string s,t;
ll n, m, dp[1005][1005];

void clean()
{
      memset(dp,-1,sizeof dp);
}

ll rec(ll posN, ll posM)
{

      if (posN>=n || posM >= m){
            return dp[posN][posM] = 0;
      }

      if (dp[posN][posM] != -1)return dp[posN][posM];
      ll t1 = 0 , t2 , t3;


      if (s[posN]==t[posM])t1 = rec(posN+1,posM+1)+1;

      t2 = rec(posN,posM+1);
      t3 = rec(posN+1,posM);

      return dp[posN][posM] = max(t1,max(t2,t3));
}

int main()
{
      while(getline(cin,s)){
            getline(cin,t);

            n = s.size();
            m = t.size();

            clean();

            printf("%lld\n",rec(0,0));
      }


      return 0;
}
