#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl
#define maxn 1005

using namespace std;

ll dp[maxn][maxn] , n;
string s;

void Clean()
{
      memset(dp,-1,sizeof dp);
}

ll rec(ll pos1, ll pos2)
{
      if (pos1>pos2)return 0;

      if (pos1==pos2) return dp[pos1][pos2] = 1;

      if (dp[pos1][pos2] != -1)return dp[pos1][pos2];

      ll t1 = rec(pos1+1,pos2-1);
      if (s[pos1]==s[pos2])t1+=2;

      ll t2 = rec(pos1+1,pos2);
      ll t3 = rec(pos1,pos2-1);

      return dp[pos1][pos2] = max(t1,max(t2,t3));
}

int main()
{
      int tc;
      scanf("%d",&tc);
      getchar();

      for (int _t = 1; _t<=tc ; _t++){
            Clean();

            getline(cin,s);
            n = s.size();

            printf("%lld\n",rec(0,n-1));
      }



      return 0;
}
