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
            bool solution = true;

            ll a,b , cnt = 0;
            cin >> a >> b;

            while(a!=b){
                  if (a>b){
                        if (a%8==0 && a/8>= b)a/=8 , cnt++;
                        else if (a%4==0 && a/4>=b)a/=4 , cnt++;
                        else if (a%2==0 && a/2>=b)a/=2,cnt++;
                        else {
                              solution = false;
                              break;
                        }
                  }
                  else {
                        if (a*8<=b)a*=8 , cnt++;
                        else if (a*4<=b)a*=4,cnt++;
                        else if (a*2<=b)a*=2 , cnt++;
                        else {
                              solution = false;
                              break;
                        }
                  }
            }
            if (!solution)cout << -1 << endl;
            else cout << cnt << endl;
      }




      return 0;
}
