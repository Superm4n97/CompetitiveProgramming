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

string s , t;
ll mx;

bool check(string ss)
{
      string sss = ss;
      reverse(sss.begin(),sss.end());
      if (sss==ss)return true;
      return false;
}

void clean()
{
      s = "";
      t = "";
      mx = 0;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            clean();

            cin >> s;

            ll n = s.size();

            ll palin = -1 , palined = n;

            for (ll i=0;i<n;i++){
                  ll j = n-i-1;

                  if (j<=i)break;

                  if (s[i]==s[j])palin = i , palined = j;
                  else break;
            }

            //for (int i=palin+1 ; i<palin+2 ; i++){
                  int fii = palin+1 , ts,td;

                  for (int j = palined-1 ; j>=0 ; j--){
                        if (j==fii){
                              ts = palin+1;
                              td = j+ts;
                              mx = td-ts;
                              break;
                        }
                        if (j<fii){
                              ts = palin+1;
                              td = j+palin;

                              mx = td - ts;

                              break;
                        }

                        if (s[j]==s[fii]){
                              fii++;
                        }
                        else {
                              fii = palin+1;
                        }
                  }
            //}
            //for (int j = palined-1 ; j>palined-2 ; j--){
                  int j = palined-1;
                  for (int i = palin+1 ; i<palined ; i++){

                        ll len = (j-i+1);

                        if (j==i){
                              ll tut = palined-1-j+td;
                              if (tut>len){
                                    td = palined-1;
                                    ts = i-(palined-1-i);
                              }
                              break;
                        }
                        if (j<i){
                              ll tut = palined-1 - (i-(palined-j));

                              if (tut>len){
                                    td = palined-1;
                                    //show(i);
                                    ts = i-(palined-i);
                              }

                              break;
                        }

                        if (s[j]==s[i]){
                              j--;
                        }
                        else {
                              j = palined-1;
                        }
                  }
            //}
           // show(ts);
           // show(td);

            for (int i=0;i<=palin;i++)cout << s[i];
            for (int i=ts ; i<=td ; i++)cout << s[i];
            for (int i = palined ; i<n;i++)cout << s[i];
            cout << endl;
      }


      return 0;
}
