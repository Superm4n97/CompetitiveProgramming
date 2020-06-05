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

ll rec(ll n)
{
      if (n==1 || n==0)return 0;

      ll b = 1 , e = n , res = 0;
      while(b<=e){
            ll mid = (b+e)/2;

            ll temp = mid*(mid+1) + mid*(mid-1)/2;

            if (temp<=n){
                  res = max(res,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }

      //show(res);

      return rec(n-(res*(res+1) + res*(res-1)/2))+1;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            cout << rec(n) << endl;
      }




      return 0;
}
