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

vll R,G,B;
ll r,g,b , ans;

ll clean()
{
      R.clear();
      G.clear();
      B.clear();
}

ll upperBoundGreen(ll a)
{
      ll b = 0 , e = G.size()-1 , res = G.size()-1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (G[mid]>=a){
                  res = min(res,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return G[res];
}

ll upperBoundBlue(ll a)
{
      ll b = 0 , e = B.size()-1 , res = B.size()-1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (B[mid]>=a){
                  res = min(res,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return B[res];
}

ll lowerBoundGreen(ll a)
{
      ll b = 0 , e = G.size()-1 , res = 0;

      while(b<=e){
            ll mid = (b+e)/2;

            if (G[mid]<=a){
                  res = max(res,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return G[res];
}

ll lowerBoundBlue(ll a)
{
      ll b = 0 , e = B.size()-1 , res = 0;

      while(b<=e){
            ll mid = (b+e)/2;

            if (B[mid]<=a){
                  res = max(res,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return B[res];
}

ll cal(ll x, ll y, ll z)
{
      ll temp  = (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);
      return temp;
}

void solve(ll x)
{
      ll y1 = upperBoundGreen(x);

      ll mid11 = upperBoundBlue((x+y1)/2);
      ans = min(ans,cal(x,y1,mid11));
      ll mid12 = lowerBoundBlue((x+y1)/2);
      ans = min(ans,cal(x,y1,mid12));


      ll y2 = lowerBoundGreen(x);

      ll mid21 = upperBoundBlue((x+y2)/2);
      ans = min(ans,cal(x,y2,mid21));
      ll mid22 = lowerBoundBlue((x+y2)/2);
      ans = min(ans,cal(x,y2,mid22));


      ll z1 = upperBoundBlue(x);
      ll mm11 = upperBoundGreen((x+z1)/2);
      ans = min(ans,cal(x,z1,mm11));
      ll mm12 = lowerBoundGreen((x+z1)/2);
      ans = min(ans,cal(x,z1,mm12));

     // show(x);
      ll z2 = lowerBoundBlue(x);
      ll mm21 = upperBoundGreen((x+z2)/2);
      ans = min(ans,cal(x,z2,mm21));
      ll mm22 = lowerBoundGreen((x+z2)/2);
      ans = min(ans,cal(x,z2,mm22));

      return;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
          clean();

          cin >> r >> g >> b;

          inputll(R,r);
          inputll(G,g);
          inputll(B,b);

          srt(R);
          srt(G);
          srt(B);


          ans = 9223372036854770000;
          //show(ans);

          for (int i=0;i<r;i++){
                  solve(R[i]);
          }
          printf("%I64d\n",ans);
      }




      return 0;
}
