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

#define maxn            205

using namespace std;

ll X[maxn],Y[maxn];
ll A[maxn],B[maxn];
ll n,m,k;
string s = "";
map < pll , ll > mp;
ll ignore[maxn];

ll normalx(ll a)
{
      if (a<1)return 1;
      if (a>n)return n;

      return a;
}

ll normaly(ll a)
{
      if (a<1)return 1;
      if (a>m)return m;

      return a;
}

int main()
{
      cin >> n >> m >> k;


      for (int i=1;i<=k;i++){
            cin >> A[i] >> B[i];
            //mp[{A[i],B[i]}]++;
            //if (mp[{A[i],B[i]}]==2)ignore[i] = 1;
      }
      for (int i=1;i<=k;i++)cin >> X[i] >> Y[i];

      for (int i=1;i<=k;i++){

            //if (ignore[i])continue;

            A[i] = normalx(A[i]);
            B[i] = normaly(B[i]);

            if (A[i] < X[i]){
                  ll temp = X[i]-A[i];
                  for (int j=0;j<temp;j++)s+="D";

                  for (int j = i+1 ; j<=k ; j++)A[j]+=temp;
            }
            if (A[i]>X[i]){
                  ll temp = A[i]-X[i];

                  for (int j=0;j<temp;j++)s+="U";

                  for (int j = i+1 ; j<=k;j++)A[j]-=temp;
            }

            if (B[i] < Y[i]){
                  ll temp = Y[i] - B[i];

                  for (int j=0;j<temp;j++)s+="R";

                  for (int j = i+1 ; j<=k ; j++)B[j]+=temp;
            }
            if (B[i] > Y[i]){
                  ll temp = B[i] - Y[i];

                  for (int j=0;j<temp;j++)s+="L";

                  for (int j = i+1 ; j<=k ; j++)B[j]-=temp;
            }
      }
      if (s.size()<=2*m*n){
            cout << s.size() << endl;
            cout << s << endl;
      }
      else cout << -1 << endl;




      return 0;
}
