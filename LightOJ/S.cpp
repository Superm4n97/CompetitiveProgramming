#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000010

using namespace std;

ll n;
ll dp[1004][1004];
string s , t = "", ch = "";

void clean()
{
      t = "";
      ch = "";
      memset(dp,-1,sizeof dp);
}

ll rec(ll pos1, ll pos2)
{
      if (pos1>=pos2)return 0;

      if (dp[pos1][pos2] != -1)return dp[pos1][pos2];

      ll t1 = inf;
      if (s[pos1]==s[pos2])t1 = rec(pos1+1,pos2-1);

      ll t2 = rec(pos1+1,pos2)+1;///s[pos1] deleted
      ll t3 = rec(pos1,pos2-1)+1;///s[pos2] deleted

      return dp[pos1][pos2] = min(t1,min(t2,t3));
}

void abarRec(ll pos1, ll pos2)
{
      if (pos1>pos2)return;

      if (pos1==pos2){
            t = t+s[pos1];
            return;
      }

      ll t1 = inf;
      if (s[pos1]==s[pos2])t1 = rec(pos1+1,pos2-1);

      ll t2 = rec(pos1+1,pos2)+1;///s[pos1] added
      ll t3 = rec(pos1,pos2-1)+1;///s[pos2] deleted

      ll mn = min(t1,min(t2,t3));

      if (t1==mn){
            t = t+s[pos1];
            ch = s[pos1]+ch;

            abarRec(pos1+1,pos2-1);
      }
      else if (t2==mn){
            t = t+s[pos1];
            ch = s[pos1]+ch;

            abarRec(pos1+1,pos2);
      }
      else {
            t = t + s[pos2];
            ch = s[pos2]+ch;

            abarRec(pos1,pos2-1);
      }
}

int main()
{
      while(cin >> s){
            n = s.size();
            clean();
            ll mn = rec(0,n-1);
            abarRec(0,n-1);

            cout << mn << " ";
            cout << t << ch  << endl;
      }


      return 0;
}
