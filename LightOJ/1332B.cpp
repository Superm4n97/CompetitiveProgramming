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

ll type[1005];

int main()
{
      for (int i=2 ; i<=1003; i++){
            if(type[i]==0){
                  type[i] = i;

                  for (int j = i*i ; j<= 1003 ; j+=i){
                        if (type[j]==0)type[j] = i;
                  }
            }
      }

      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5];
            ll c[n+5];
            map < ll , ll > mp;

            for (int i=0;i<n;i++)cin >> A[i];

            ll counter = 1;

            for (int i=0;i<n;i++){
                  c[i] = type[A[i]];
                  if (mp[c[i]]==0){
                        mp[c[i]] = counter;
                        counter++;
                  }
            }
            for (int i=0;i<n;i++){
                  c[i] = mp[c[i]];
            }
            cout << counter-1 << endl;
            for (int i=0;i<n;i++)cout << c[i] << " ";
            cout << endl;
      }




      return 0;
}
