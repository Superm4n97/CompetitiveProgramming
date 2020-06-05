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

ll n, A[maxn],C[maxn] , t1 , t2;

int main()
{
      cin >> n;
      string s;
      cin >> s;

      for (int i=1;  i<=n; i++){
            if (s[i-1]=='(')A[i] = 1 , t1++;
            else A[i] = -1 , t2++;
      }

      if (t1 != t2){
            cout << -1 << endl;
            return 0;
      }

      for (int i=1; i<=n ; i++)C[i] = C[i-1]+A[i];
      ll prev = 0 , ans = 0;
      for (int i=1 ; i<=n; i++){
            if (C[i]==-1 && prev==0)prev = i;

            if (C[i]==0){
                  if (prev!=0){
                        ans+=(i-prev+1);
                        prev = 0;
                  }
            }
      }
      cout << ans << endl;





      return 0;
}
