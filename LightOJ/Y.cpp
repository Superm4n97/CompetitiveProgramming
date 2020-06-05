#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[10004][3][102] , n,k , A[10004];

void Clean()
{
      memset(dp,-1,sizeof dp);
      memset(A,0,sizeof A);
}

ll sum(ll a, ll b)
{
      a+=b;
      if (a>k)a-=k;

      return a;
}

ll sub(ll a, ll b)
{
      a-=b;
      if(a<0)a += k;

      return a;
}

ll rec(ll pos, ll type , ll mod)
{
      if (pos==n){
            if (mod==0){
                  return 1;
            }
            return 0;
      }

      if (dp[pos][type][mod] != -1)return dp[pos][type][mod];

      ll temp;

      if (type==0){
            temp = sub(mod,A[pos+1]);
      }
      else {
            temp = sum(mod,A[pos+1]);
      }

      ll t1 = rec(pos+1,0,temp);
      ll t2 = rec(pos+1,1,temp);

      ll t = 0;
      if (t1+t2>0)t = 1;

      return dp[pos][type][mod] = t;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            Clean();

            scanf("%lld %lld",&n,&k);
            for (int i=1;i<=n;i++){
                  scanf("%lld",&A[i]);

                  A[i]%=k;
                  if (A[i]<0)A[i]+=k;
            }

            if (rec(1,0,A[1]) + rec(1,1,A[1]))printf("Divisible\n");
            else printf("Not divisible\n");
      }


      return 0;
}
