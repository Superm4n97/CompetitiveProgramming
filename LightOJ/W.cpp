#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000010

using namespace std;

struct data
{
      ll len,occurance;
};

ll n,m;
data dp[65][35][35];
string s,t;

void clean()
{
      for (int i = 0; i<64 ; i++){
            for (int j=0 ; j<34 ; j++){
                  for (int k = 0; k<34 ;k++){
                        dp[i][j][k].len = -1;
                        dp[i][j][k].occurance = 0;
                  }
            }
      }
}

data combine(data d1, data d2)
{
      if (d1.len<d2.len)return d1;
      if (d2.len<d1.len)return d2;

      data dt;
      dt.len = d1.len;
      dt.occurance = d1.occurance+d2.occurance;

      return dt;
}

data rec(ll pos, ll ptr1, ll ptr2)
{
      if (dp[pos][ptr1][ptr2].len != -1)return dp[pos][ptr1][ptr2];

      if (ptr1==n || ptr2==m){

            if (ptr1==n && ptr2==m){
                  data dt;
                  dt.len = pos;
                  dt.occurance = 1;

                  return dp[pos][ptr1][ptr2] = dt;
            }

            if (ptr1==n)return dp[pos][ptr1][ptr2] = rec(pos+1,ptr1,ptr2+1);

            return dp[pos][ptr1][ptr2] = rec(pos+1,ptr1+1,ptr2);
      }

      data t2,t3;

      if (s[ptr1]==t[ptr2])return dp[pos][ptr1][ptr2] = rec(pos+1,ptr1+1,ptr2+1);

      t2 = rec(pos+1,ptr1,ptr2+1);
      t3 = rec(pos+1,ptr1+1,ptr2);

      return dp[pos][ptr1][ptr2] = combine(t2,t3);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            clean();

            cin >> s;
            cin >> t;
            n = s.size();
            m = t.size();

            data temp = rec(0,0,0);

            printf("Case %d: %lld %lld\n",_t,temp.len,temp.occurance);
      }


      return 0;
}
