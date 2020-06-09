#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

ll n , k;
string st[13];
ll dp[2005][15];
ll D[2005][2005];

vector < ll > v;

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

ll comp(string s1 , string s2)
{
      ll cnt = 0;

      for (int i=0 ; i<7 ; i++){
            if (s1[i]=='0' && s2[i]=='1')cnt++;
            if (s1[i]=='1' && s2[i]=='0')return -1;
      }
      return cnt;
}

ll rec(ll pos, ll W)
{
      if (D[pos][W] != -1)return D[pos][W];

      if (pos == n){
            if (W == 0){
                  return D[pos][W] = 1;
            }
            else return D[pos][W] = 0;
      }

      ll temp = 0;

      for (int i=0 ; i<=9 ; i++){
            if (dp[pos][i]==-1 || W<dp[pos][i])continue;

            temp = max(rec(pos+1,W-dp[pos][i]),temp);
      }


      return D[pos][W] = temp;
}

void trace(ll pos, ll W)
{
      if (pos==n)return;
      for (int i = 9 ; i>=0 ; i--){
            ll temp = dp[pos][i];

            if (temp>W)continue;

            if (D[pos+1][W-temp] > 0){


                  //v.pb(i);
                  cout << i ;
                  trace(pos+1,W-temp);
                  return;
            }
      }
}

int main()
{
      build();

      cin >> n >> k;

      for (int i=0;i<n ; i++){
            string s;
            cin >> s;

            for (int j=0 ;j<=9 ; j++){
                  ll temp = comp(s,st[j]);

                  dp[i][j] = temp;
            }
      }



      rec(0LL,k);


      if(D[0][k] == 0)cout << -1 ;
      else {
            trace(0,k);
            //rsrt(v);

            //for (int i=0;i<n;i++)cout << v[i];
      }



      return 0;
}
