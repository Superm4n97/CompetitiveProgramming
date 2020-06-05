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

ll sum(ll a)
{
      return a*(a+1)/2;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;

            ll n = x2-x1 , m = y2 - y1;

            if (n>m)swap(n,m);

            if (n==0)cout << 1 << endl;
            else {
                  cout << 2*sum(n-1) + ((m+n-1) - 2*(n-1))*n + 1<< endl;
            }
      }




      return 0;
}
