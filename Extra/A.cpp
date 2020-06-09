#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll dp[21][6][3];
vector < ll > v;

void buildVector(ll a)
{
      v.clear();

      if (a==0){
            v.push_back(0LL);
            return;
      }

      while(a){
            ll temp = a%10;
            v.push_back(temp);
            a/=10;
      }
      reverse(v.begin(),v.end());
}

ll rec(ll pos, ll presum , ll lessthan)
{
      if (dp[pos][presum][lessthan] != -1)return dp[pos][presum][lessthan];
      if (presum == 3)return dp[pos][presum][lessthan] = 1;
      if (pos>=v.size())return dp[pos][presum][lessthan] = 1;

      if (lessthan){
            ll temp = rec(pos+1,presum,lessthan);
            temp += rec(pos+1 , presum+1 , lessthan)*9;

            return dp[pos][presum][lessthan] = temp;
      }
      else {
            if (v[pos]==0) return dp[pos][presum][lessthan] = rec(pos+1,presum,0);

            ll temp = rec(pos+1 , presum , 1);
            temp += (rec(pos+1,presum+1,1))*(v[pos]-1);
            temp += rec(pos+1,presum+1,0);

            return dp[pos][presum][lessthan] = temp;
      }
}

ll solve(ll a)
{
      ll ret = 0;

      buildVector(a);
      memset(dp,-1,sizeof dp);

//      for (int i=0;i<v.size();i++)cout << v[i] << " ";
//      cout << endl;

      for (ll i=0 ; i<=v[0] ; i++){
            if (i==v[0]){
                  ll ps = 1;
                  if (v[0]==0)ps = 0;

                  ret += rec(1,ps,0);
            }
            else if (i==0){
                  ret+=rec(1,0,1);
            }
            else ret+=rec(1,1,1);
      }

      return ret;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a, b;
            cin >> a >> b;
            ll ansB = solve(b) , ansA = solve(a-1);
//            show(ansB);
//            show(ansA);
            cout << ansB - ansA << endl;
      }



      return 0;
}
