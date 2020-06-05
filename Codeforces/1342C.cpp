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

ll cal(ll x, ll lc)
{

}

int main()
{
      /*ll a = 3 , b = 6;
      for (int i=0 ; i<=50 ; i++){
            if (i%b == 0)cout << endl;
            cout << i << " " << (i%a) % b << " " << (i%b) %a << endl;
      }*/

      int tc;
      cin >> tc;

      while(tc--){
            ll a,b,q;
            cin >> a >> b >> q;

            if (a>b)swap(a,b);

            ll lc = a*b / __gcd(a,b);

            while(q--){
                  ll l,r;
                  cin >> l >> r;

                  if(lc==b)cout << 0 << " " ;
                  else {
                        ll x = l-1  ,ans1 = 0 , ans2 = 0;

                        ll temp = x/lc;

                        if (x<lc){
                              ans1 = min(b,x+1);
                        }
                        else {
                              ans1+=min(b,x+1);

                        if (temp>0)ans1+=(temp-1)*b;

                        temp*=lc;
                        ans1+= min(b,x-temp+1);
                        }





                        x = r;
                        temp = x/lc;

                        if (x<lc){
                              ans2 = min(b,x+1);
                        }
                        else {
                              ans2+=min(b,x+1);

                        if (temp>0)ans2+=(temp-1)*b;

                        temp*=lc;

                        ans2+=min(b,x-temp+1);
                        }

                        ll t = ans2 - ans1;

                        cout << r-l+1 - t << " ";
                  }
                  cout << endl;
            }
      }




      return 0;
}
