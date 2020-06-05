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
      scl(tc);

      while(tc--){
            ll n,k , len;
            string s;
            cin >> n >> k;
            cin >> s;

            len = n/k+5;

            ll A[len];
            ll ans , total = 0;

            for (int i=0 ; i<n; i ++){
                  if (s[i]=='1')total++;
            }
            ans = inf;

            for (int i = 0 ; i<k;i++){
                  memset(A,0,sizeof A);
                  ll id = 1 , temp = 0 , cnt=0;

                  for (int j = i ; j<n ; j+=k){
                        if (s[j]=='1')A[id] = 1;
                        id++;
                  }

                  for (int j=0 ; j<len ; j++){
                        if (A[j]==0){
                              temp = max(temp,cnt);
                              cnt = 0;
                        }
                        else{
                              cnt++;
                              temp = max(temp,cnt);
                        }
                  }

                  ans = min(ans,total-temp);
            }
            printf("%I64d\n",ans);
      }




      return 0;
}
