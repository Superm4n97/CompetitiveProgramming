///Unsuccessful Time Limit due to use of map
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007
#define mod2 1000000009
#define maxn 1000006
#define _p 5 /// _p is

using namespace std;

ll P[55] , P2[55] , H[55];
ll mp[maxn];
ll mp2[maxn];
//string s;

ll checkOut(char ch)
{
      if (ch == 'A')return 4;
      if (ch == 'C')return 1;
      if (ch == 'G')return 2;
      if (ch == 'T')return 3;
}

ll normal(ll a)
{
      if (a<mod)return a;

      ll temp = a/mod;
      if (mod*temp == a)return 0;

      temp++;
      temp*=mod;

      return temp - a;
}

int main()
{
      P[0] = P2[0] = 1;
      for (ll i=1 ; i<55 ; i++){
            P[i] = P[i-1]*31;
            P[i] = normal(P[i]);

            //P2[i] = P2[i-1]*2;
            //P2[i] %= mod2;
      }

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            int n;
            scanf("%d",&n);
            ll ans = 0;
            //memset(mp,0,sizeof mp);
            map < ll , ll > mp;

            while(n--){
                  string s;
                  cin >> s;

                  for (int i = 0 ; i<s.size() ; i++){
                        H[i] = P[i]*checkOut(s[i]);
                        H[i] = normal(H[i]);
                        H[i]+=H[i-1];
                        H[i] =normal(H[i]);
                  }

                  for (ll i=0 ; i<s.size();i++){
                        mp[H[i]]++;
                        ans = max(ans,mp[H[i]]*(i+1));
                  }
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
