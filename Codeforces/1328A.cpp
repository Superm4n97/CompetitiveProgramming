#include<bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)
#define mod             1000000007
#define maxn            200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;

            vector < ll > v,G[maxn];

            for (int i=0;i<n;i++){
                  ll a;
                  cin >> a;
                  v.pb(a);
            }


            for (int i=0;i<n;i++){
                  if (i==n-1){
                        if (v[i]!=v[i+1]){
                              G[v[i]].pb(v[i+1]);
                              G[v[i+1]].pb(v[i]);
                        }
                  }
                  else if (i=n-1){
                        if (v[0]!=v[n-1]){
                              G[v[0]].pb(v[n-1]);
                              G[v[n-1]].pb(v[0]);
                        }
                  }
            }
      }





      return 0;
}
