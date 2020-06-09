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
            ll n;
            cin >> n;

            vector < ll > G[n+3];

            for (int i=1;i<=n;i++){
                  ll m;
                  cin >> m;

                  for (int j=0;j<m;j++){
                        ll a;
                        cin >> a;
                        G[i].pb(a);
                  }
                  if (m)srt(G[i]);
            }

            int A[n+4] , B[n+4] , cnt = 0;
            memset(A,0,sizeof A);
            memset(B,0,sizeof B);

            for (int i=1;i<=n;i++){
                  for (int j=0;j<G[i].size();j++){
                        ll v = G[i][j];
                        if (B[v]==0){
                              A[i] = B[v] = 1;
                              cnt++;
                              break;
                        }
                  }
            }
            if (cnt==n)cout << "OPTIMAL" << endl;
            else {
                  cout << "IMPROVE" << endl;
                  ll a, b;

                  for (int i=1;i<=n;i++){
                        if (A[i]==0){
                              a = i;
                              break;
                        }
                  }
                  for (int i=1;i<=n;i++){
                        if (B[i]==0){
                              b = i;
                              break;
                        }
                  }
                  cout << a << " "<< b << endl;
            }
      }




      return 0;
}
