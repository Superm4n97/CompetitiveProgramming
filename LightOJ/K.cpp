#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 1000006
#define inf 10000000000000000
#define mod 1000000000

using namespace std;

struct data{
      ll value , numberOfCoins;
};

data dp[105][10004];
ll n, k, A[105];

void clean()
{
      for (int i=0;i<103;i++){
            for (int j=0;j<10003;j++)dp[i][j].value = -1 , dp[i][j].numberOfCoins = 0;
      }
}

data compare(data d1, data d2)
{
      if (d1.value<d2.value)return d1;
      if (d1.value>d2.value)return d2;

      if (d1.numberOfCoins<d2.numberOfCoins)return d1;
      return d2;
}

data rec(ll pos, ll ammount)
{
      if (ammount>=k){
            data dt;

            dt.value = ammount - k;
            dt.numberOfCoins = 0;

            return dt;
      }

      if (pos>n){
            data dt;
            dt.value = inf;
            dt.numberOfCoins = inf;

            return dp[pos][ammount] = dt;
      }

      if (dp[pos][ammount].value != -1)return dp[pos][ammount];

      data dt1 = rec(pos+1,ammount);
      data dt2 = rec(pos+1,ammount + A[pos]);
      dt2.numberOfCoins++;

      return dp[pos][ammount] = compare(dt1,dt2);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            clean();
            scanf("%lld %lld",&k,&n);

            for (int i=1;i<=n;i++)scanf("%lld",&A[i]);
            data temp = rec(1,0);
            printf("%lld %lld\n",k+temp.value ,temp.numberOfCoins);
      }



      return 0;
}
