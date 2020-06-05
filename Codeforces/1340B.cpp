#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2005

using namespace std;

string st[15];
ll D[maxn][15];
ll dp[maxn][maxn] , n , k;

void build()
{
      memset(dp,-1,sizeof dp);
      memset(D,-1,sizeof D);

      st[0] = "1110111";
      st[1] = "0010010";
      st[2] = "1011101";
      st[3] = "1011011";
      st[4] = "0111010";
      st[5] = "1101011";
      st[6] = "1101111";
      st[7] = "1010010";
      st[8] = "1111111";
      st[9] = "1111011";
}

ll compare(string s1, string rf)
{
      ll cnt = 0;
      for (int i=0 ; i<7 ; i++){
            if (s1[i] == '0' && rf[i]== '1')cnt++;
            if (s1[i] == '1' && rf[i] == '0')return -1;
      }
      return cnt;
}

ll rec(ll pos , ll W)
{
      if (dp[pos][W] != -1)return dp[pos][W];

      if (pos == n){
            if (W==0)return dp[pos][W] = 1;
            else return dp[pos][W] = 0;
      }

      ll res = 0;

      for (int i=0 ; i<=9 ; i++){
            if (D[pos][i] == -1 || D[pos][i]>W)continue;

            res = max(res,rec(pos+1 , W - D[pos][i]));
      }

      return dp[pos][W] = res;
}

void trace(ll pos, ll W)
{
      if (pos==n)return;

      for (int i=9 ; i>=0 ; i--){
            if (D[pos][i] ==-1 || W<D[pos][i])continue; ///check kor

            if (dp[pos+1][W-D[pos][i]] == 1){
                  cout << i ;
                  trace(pos+1 , W - D[pos][i]);
                  return;
            }
      }
}

int main()
{
     build();

     cin >> n >> k;

     for (int i=0 ; i<n ; i++){
            string s;
            cin >> s;

            for (int j = 0 ; j<=9 ; j++){
                  ll temp = compare(s,st[j]);
                  D[i][j] = temp;
            }
     }

     if (rec(0,k) == 0)cout << -1 << endl;
     else {
            trace(0,k);
     }



      return 0;
}
