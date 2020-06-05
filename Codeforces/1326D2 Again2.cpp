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

ll failure[maxn];

ll KMP(string &s)
{
      ll n = s.size();

      failure[0] = failure[1] = 0;

      for (int i=2 ; i<=n ; i++){///
            ll j = failure[i-1];

            while(true){
                  if (s[j]==s[i-1]){///i-1
                        failure[i] = j+1;
                        break;
                  }
                  if (j==0){
                        failure[i] = 0;
                        break;
                  }

                  j = failure[j];
            }
      }

      ll i = 0 , j = n-1;

      while(true){
            if (s[i]==s[j]){

                  if (i==j)return i*2+1;
                  if (i+1 == j)return (i+1)*2;
                  if (i>j)return i*2;

                  i++ , j--;
            }
            else {
                  if (i==0)j--;
                  else i = failure[i];
            }
      }

      return false;
}

int main()
{
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      int tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;

            ll n = s.size();
            ll x = 0 , y = n-1;

            while(x<y){
                  if (s[x] == s[y])x++ , y--;
                  else break;
            }

            if (x>=y){
                  cout << s << "\n";
                  continue;
            }

            string s1 = "" , s2 = "" , ans = "";

            for (int i=x ; i<=y ; i++)s1.push_back(s[i]);

            s2 = s1;
            reverse(s2.begin(),s2.end());

            ll len1 = KMP(s1) , len2 = KMP(s2);

            for (int i=0 ; i<x; i++)ans.push_back(s[i]);
            if (len1>=len2){
                  for (int  i = 0 ; i<len1 ; i++)ans.push_back(s1[i]);
            }
            else {
                  for (int i=0 ; i<len2 ; i++)ans.push_back(s2[i]);
            }
            for (int i = y+1 ; i<n; i++)ans.push_back(s[i]);

            cout <<ans<< "\n";
      }


      return 0;
}
