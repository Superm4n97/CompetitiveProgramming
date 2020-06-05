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

vll MX, MN ;
ll n,m;

void clean()
{
      MX.clear();
      MN.clear();
}

ll binarySearchMX(ll a)
{
      ll b = 0 , e = MX.size()-1 , res = -1;

      while(b<=e){
            ll mid = (b+e)/2;

            if (MX[mid]<=a){
                  b = mid +1;
                  res = max(res,mid);
            }
            else e = mid-1;
      }

      return res+1;
}

ll binarySearchMN(ll a)
{
      ll b = 0LL , e = MN.size()-1 , res = MN.size();

      while(b<=e){
            ll mid = (b+e)/2;

            if (MN[mid]>=a){
                  e = mid-1;
                  res = min(res,mid);
            }
            else {
                  b = mid+1;
            }
      }

      return MN.size() - res;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
           clean();

           scll(n,m);
           ll A[n+5];
           ll sum[2*m+5];

           memset(sum,0,sizeof sum);

           for (int i=1 ; i<=n;i++)scl(A[i]);

           ll x = 1 , y = n;

           while(x<y){
                  ll temp = A[x]+A[y];
                  sum[temp]++;

                  MX.push_back(max(A[x],A[y]));
                  MN.push_back(min(A[x],A[y]));

                  x++;
                  y--;
           }
           srt(MX);
           srt(MN);

           ll ans = inf;

           for (int i=2 ; i<= m*2 ; i++){
                  ll t1 = binarySearchMX(i-m-1) , t2 = binarySearchMN(i);

                  ll temp = n/2 - (t1+t2+sum[i]) + (t1+t2)*2;
                  ans = min(ans,temp);
           }

           cout << ans << endl;

      }




      return 0;
}
