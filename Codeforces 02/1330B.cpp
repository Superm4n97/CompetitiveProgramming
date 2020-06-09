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
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            ll cnt[n+5] , A[n+5] , c[n+5];
            memset(cnt,0,sizeof cnt);
            memset(c,0,sizeof c);

            for (int i=1;i<=n;i++)cin >> A[i];

            ll mx = 0;
            bool valid = true;

            for (int i=1;i<=n;i++){
                  cnt[A[i]]++;
                  if (cnt[A[i]]>1){
                        valid = false;
                  }
                  mx = max(mx,A[i]);

                  if (valid && mx == i){
                        c[i] = 1;
                  }
            }

            mx = 0;
            valid = true;
            memset(cnt,0,sizeof cnt);

            for (int i=n ; i>=1 ; i--){
                  cnt[A[i]]++;
                  if (cnt[A[i]] > 1){
                        valid = false;
                  }
                  mx = max(mx,A[i]);

                  if (valid && mx==(n-i+1)){
                        c[i-1]++;
                  }
            }

            vector < pll > vp;

            for (int i=1;i<=n;i++){
                  if (c[i]==2){
                        vp.pb({i,n-i});
                  }
            }
            cout << vp.size() << endl;
            for (int i=0;i<vp.size();i++){
                  cout << vp[i].first << " " << vp[i].second << endl;
            }
      }




      return 0;
}
