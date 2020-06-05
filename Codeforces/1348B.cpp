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

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,k;
            cin >> n >> k;
            vll v;
            map < ll , ll > mp;
            ll cnt = 0;

            for (int i=0 ; i<n;i++){
                  ll a;
                  cin >> a;
                  mp[a]++;
                  cnt = max(cnt,mp[a]);

                  if (mp[a]==1)v.push_back(a);
            }

            if (v.size()>k)cout << -1 << endl;
            else {
                  while(v.size()<k)v.push_back(1);

                  cout << v.size()*n << endl;

                  for (int i=0 ; i<n; i++){
                        for (int j = 0 ; j<v.size() ; j++)cout << v[j] << " ";
                  }
                  cout << endl;
            }
      }




      return 0;
}
