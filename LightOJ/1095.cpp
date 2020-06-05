#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1003
#define mod 1000000007

using namespace std;

ll D[maxn] , C[maxn][maxn] , F[maxn];

ll normal(ll a)
{
      if (a<mod)return a;

      ll temp = a/mod;
      if (mod*temp == a)return a;

      temp++;
      return temp*mod-a;
}

ll nCr(ll n, ll r)
{
      if (C[n][r] != -1)return C[n][r];
      if (r==1)return C[n][r] = n;
      if (n==r)return C[n][r] = 1;

      return C[n][r] = normal(nCr(n-1,r)+nCr(n-1,r-1));
}

ll DIS(ll a)
{
      if (D[a]!=-1)return D[a];
      if (a<2)return D[a] = 1-a;

      return D[a] = normal((a-1)*(DIS(a-1)+DIS(a-2))); ///could be overflow
}

int main()
{
      memset(D,-1,sizeof D);
      memset(C,-1,sizeof C);
      memset(F,-1,sizeof F);

      F[1] = 1;
      for (ll i = 2 ; i<maxn ; i++)F[i] = normal(F[i-1]*i);

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,m,k;
            scanf("%lld %lld %lld",&n,&m,&k);

            show(C[m][k]);
            show(nCr(m,k));
            show(F[k]);
            show(DIS(n-k));

            ll temp = normal(nCr(m,k));
            temp = normal(temp*DIS(n-k));

            printf("Case %d: %lld\n",_t,temp);
      }
}
/*
5 3 2
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3

1 2 3 4 5

3C2*2! * D(5-2)
mCk * D(n-k)

D(1) = 0
D(2) = 1
D(3) = 2

 1 2 3 4
-4 - - 1 (n-1)*D(n-2)
-4 - - - (n-1)*D(n-1)
(n-1)*(D(n-2)+D(n-1))

1-1
1-0
2-1
3-2
4-3*(2+1) - 9
5-4*(11) - 44
6-5*53 - 265
...
...

5 ta ghor 2 ta kokhono nijer position e boshte parbe na

|1 2 3|  4 5
|2 1 -|  - -
|3 - 1|  - -
|- 3 2|  - -
n*(n-1) * dis(n-2 , k-2)

*/
