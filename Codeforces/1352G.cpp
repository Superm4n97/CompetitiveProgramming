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
            ll n;
            cin >> n;
            if (n<4)cout << -1 << endl;
            else {
                  ll cnt = 1 , temp = n/4;

                  for (int i=1 ; i<temp ; i++){
                        ll a = cnt , b = cnt+1 , c = cnt+2 , d = cnt+3;
                        cnt+=4;

                        if (i%2)cout << c << " " << a << " " << d << " " << b << " ";
                        else cout << b << " " << d << " " << a << " " << c << " ";
                  }

                  //ll a = 0,b = 0,c = 0;
                  if (temp%2){
                        if (n%4==0)cout << cnt+2 << " " << cnt << " " << cnt+3 << " " << cnt+1 << endl;
                        else if (n%4==1)cout << cnt+2 << " " << cnt+4 << "  " << cnt << " " << cnt+3 << " " << cnt+1 << endl;
                        else if (n%4==2)cout << cnt << " " << cnt+2<< " " << cnt+5 << " " << cnt+3<< " " << cnt+1 << " " << cnt+4 << endl;
                        else cout << cnt << " " << cnt+2<< " " << cnt+5 << " " << cnt+3<< " " << cnt+1 << " " << cnt+4 << " " << cnt+6 << endl;
                  }
                  else{
                        if (n%4==0)cout << cnt+1 << " " << cnt+3 << " " << cnt << " " << cnt+2 << endl;
                        else if (n%4==1)cout << cnt+1 << " " << cnt+3 << "  " << cnt << " " << cnt+4 << " " << cnt+2 << endl;
                        else if (n%4==2)cout << cnt << " " << cnt+2<< " " << cnt+5 << " " << cnt+3<< " " << cnt+1 << " " << cnt+4 << endl;
                        else cout << cnt << " " << cnt+2<< " " << cnt+5 << " " << cnt+3<< " " << cnt+1 << " " << cnt+4 << " " << cnt+6 << endl;
                  }
            }

      }



      return 0;
}

