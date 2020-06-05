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

ll M[50];
map < ll , ll > mp;

int main()
{
      M[0] = 1;
      for (ll i=1 ; i<= 45 ; i++){
            M[i]  = M[i-1]*2;
            mp[M[i]] = i;
      }
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            vll v;


            for (ll i=0 ; n>=M[i] ; i++){
                  v.pb(M[i]);

                  n-=M[i];

            }

            if (n){
                  for (ll i=43 ; i>=0 ; i--){
                        if (M[i]<=n){
                              v.pb(M[i]);
                              n-=M[i];
                        }
                  }
            }

            srt(v);

            cout << v.size()-1 << endl;
            for (int i=1 ; i<v.size() ; i++){
                  if (v[i]==v[i-1])cout << 0 << " ";
                  else cout << v[i]/2 << " ";
            }
            cout << endl;
      }




      return 0;
}
