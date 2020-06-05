#include<bits/stdc++.h>
#define maxn 1005
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define sqt 1.41421356

using namespace std;

vector < pair < ll , ll > > X,Y;
ll n,m , k;
ll dp[105][105];

ll rec(ll pos, ll last)
{
      show(pos);
      show(k);
      if (pos==k){
            if (X[last].first<X[pos].first && X[last].second<X[pos].second && X[pos].first<=n && X[pos].second<=m)
                  return dp[pos][last] = 1;
            return dp[pos][last] = 0;
      }

      ll t1 = rec(pos+1,last);
      ll t2 = 0;

      if (X[last].first<X[pos].first && X[last].second<X[pos].second && X[pos].first<=n && X[pos].second<=m)
            t2 = rec(pos+1,pos)+1;

      return dp[pos][last] = max(t1,t2);
}

int main()
{
      scanf("%lld %lld",&n,&m);
      scanf("%lld",&k);

      for (int i=0;i<k;i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);

            X.push_back({a,b});
            Y.push_back({b,a});
      }

      X.push_back({0,0});
      Y.push_back({0,0});

      if (k){
            sort(X.begin(),X.end());
            sort(Y.begin(),Y.end());
      }

      ll xx = 0 ,yy =0 , cnt1 = 0 , cnt2 = 0;

      for (int i=0;i<k;i++){
            if (X[i].first>xx && X[i].second>yy && X[i].first<=n && X[i].second<=m){
                  cnt1++;
                  xx = X[i].first ;
                  yy = X[i].second;
            }
      }


      xx =0;
      yy = 0;

      for (int i=0;i<k;i++){
            if (Y[i].first>xx && Y[i].second>yy && Y[i].first<=n && Y[i].second<=m){
                  cnt2++;
                  xx = Y[i].first ;
                  yy = Y[i].second;
            }
      }

      //ll cnt = max(cnt1,cnt2);

      ll cnt = rec(1,0);

      n-=cnt,m-=cnt;

      double d = (double)cnt*sqrt(2)*100.0+0.5;
      ll ans = n*100+m*100+d;

      printf("%lld\n",ans);
}
