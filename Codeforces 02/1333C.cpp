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

#define maxn            300005

using namespace std;

ll n,A[maxn] , sum = 0 , ans = 0;
map < ll , ll > mp;

ll cal(ll a)
{
      if (a<=0)return 0;

      return a*(a+1)/2;
}

int main()
{
      cin >> n;
      ll cnt = 0 , pre = 1;

      for (int i=1;i<=n;i++){
            cin >> A[i];
            mp[sum] = i;

            //cout << sum << " ";

            ll need = sum - (A[i]*-1);
            ll temp = mp[need];

            if (temp >= pre){
                  ans += cal(i  - pre );
                  ans -= cal(i-temp-1);

                 // show(i);
                  //show(ans);

                  pre = temp+1;
            }
            if (i==n){
                  ans += cal(n-pre+1);
            }

            sum+=A[i];

      }
      cout << ans << endl;



      return 0;
}
