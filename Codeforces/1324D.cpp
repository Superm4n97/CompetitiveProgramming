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

#define maxn            200005

using namespace std;

vll v;
ll A[maxn];

int main()
{
      ll n;
      cin >> n;
      for (int i=0;i<n;i++)cin >> A[i];
      for (int i=0;i<n;i++){
            ll b;
            cin >> b;
            v.pb(A[i]-b);
      }
      srt(v);

      ll ans = 0;


      for (ll i=0;i<n-1;i++){
            ll idx = n , b = 0 , e = n-1;

            while(b<=e){
                  ll mid = (b+e)/2;
                  if (v[mid]+v[i] > 0){
                        e = mid-1;
                        idx = min(idx,mid);
                  }
                  else b = mid+1;
            }

            idx = max(i+1,idx);
            ans+=n-idx;
      }

      cout << ans << endl;



    return 0;
}
