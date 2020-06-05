
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

            ll A[n+3];
            set < ll > st;


            for (int i=1;i<=n;i++){
                  cin >> A[i];
                  st.insert(A[i]);
            }

            bool adj = false;

            for (int i=1;i<=n;i++){
                  if (i==n){
                        if (A[i]==A[1])adj = true;
                  }
                  else {
                        if (A[i]==A[i+1])adj = true;
                  }
            }

            if (st.size()==1){
                  cout << 1 << endl;
                  for (int i=1;i<=n;i++)cout << 1 << " ";
                  cout << endl;
            }
            else if (adj || n%2==0){
                  cout << 2 << endl;
                  if (n%2==0){
                        for (int i=1;i<=n;i++){
                              if (i%2)cout << 1 << " ";
                              else cout << 2 << " ";
                        }
                  }
                  else {
                        ll c[n+5];
                        c[1] = 1;

                        for (int i=2;i<=n;i++){
                              if (adj && A[i]==A[i-1]){
                                    c[i] = c[i-1];
                                    adj = false;
                              }
                              else {
                                    if (c[i-1]==1)c[i] = 2;
                                    else c[i] = 1;
                              }
                        }
                        for (int i=1;i<=n;i++)cout << c[i] << " ";
                  }

                  cout << endl;
            }
            else {
                  cout << 3 << endl;
                  for (int i=0;i<n;i++){
                        ll temp = (i%3)+1;

                        if (i==n-1 && (n-1)%3==0)cout << 2;
                        else cout << temp << " ";
                  }
                  cout << endl;
            }
      }




      return 0;
}
