#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n , A[maxn];
pair < ll , ll > dp[maxn][63][4];

pair <ll , ll > rec(ll pos, ll type, ll mex)
{
      if (dp[pos][type][mex] != -1)return dp[pos][type][mex];

      if (type==0){

            pair < ll , ll > temp = rec(pos+1,1,A[pos]+30);
            ll t1 = temp.first+A[pos] - temp.second;
      }
}

int main()
{
      cin >> n;
      for (int i = 1; i<=n;i++)cin >>A[i];



      return 0;
}
