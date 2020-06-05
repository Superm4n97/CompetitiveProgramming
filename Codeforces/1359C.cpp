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
            ll h,c,t;
            cin >> h >> c >> t;

            ll b  = 1 , e = 1e9+1;
            ll ans1 = 1 , diff1 = 1e9+7 , offset = 1;
            while(b<=e){
                  ll mid = (b+e)/2;
                  if (mid%2==0)mid--;

                  ll hot = (mid+1)/2 , cool = mid/2;

                  ll temp = hot*h+cool*c;

                  if (temp<t*mid){
                        ll dd = t*mid-temp;
                        if (dd*offset<diff1*mid){
                              ans1 = mid;
                              diff1 = dd;
                              offset = mid;
                        }
                        b = mid+2;
                        //e = mid-2;
                  }
                  else {
                        ll dd = temp - t*mid;
                        if (dd*offset < diff1*mid){
                              ans1 = mid;
                              diff1 = dd;
                              offset = mid;
                        }
                        if (dd*offset==diff1*mid){
                              ans1 = min(ans1,mid);
                        }
                        e = mid-2;
                        //b = mid+2;
                  }
            }
            show(diff1);
            show(ans1);
            ll diff2 = h+c;

            if (diff2<t*2)diff2 = t*2 - diff2;
            else diff2 = diff2 - t*2;

            if (diff2*offset <= diff1*2){
                  if (diff1*2 == diff2*offset)ans1 = min(ans1,2LL);
                  else ans1 = 2;
            }

            cout << ans1 << endl;
      }




      return 0;
}

