#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define mod 1000000007

using namespace std;

ll n,m , C[30+maxn][30];

ll nCr(ll n, ll r)
{
      if (r==1)return n;
      if (r==n)return 1;

      if (C[n][r] != -1)return C[n][r];

      return C[n][r] = (nCr(n-1,r-1)+nCr(n-1,r)) % mod;
}

int main()
{
      memset(C,-1,sizeof C);
      cin >> n >> m;
      cout << nCr(n+2*m-1 , 2*m) << endl;

      return 0;
}
