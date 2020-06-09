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
#define mk              make_pair
#define inf8            100000008
using namespace std;
ll mod = 998244353;
ll A[11][22] , n;
ll T[100005];
//ll P[19] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10%mod,1e11%mod,1e12%mod,1e13%mod,1e14%mod,1e15%mod,1e16%mod,1e17%mod,1e18%mod};

int main()
{
    T[0]=1;
    for (int i=1;i<100004;i++){
       T[i] = (T[i-1]*10)%mod;
    }
    ll sz = 0;
    scl(n);
    for (int j=0;j<n;j++){
        string s;
        cin >> s;
        sz = s.size()*2;

        for (int i=0;i<s.size();i++){
            ll temp = s[i] - '0';
            A[temp][i*2]+=n;
            A[te    mp][i*2+1]+=n;
            /*A[temp][i+s.size()]++;
            A[temp][i*2] +=(n-1);
            A[temp][i*2+1] +=(n-1);*/
        }
    }
    ll ans = 0;
        ///
/*
   for (int i=1;i<=8;i++){
        for (int j=0;j<8;j++)cout << A[i][j] << " ";
        cout << endl;
    }

    for (int i=0;i<10;i++){
        cout << T[i] << " ";
    }
        cout << endl;
    */

    for (ll i=1;i<11;i++){
        for (ll j=0;j<22;j++){
            ll temp = sz - 1 - j;
            ll kotobar = A[i][j];
             ans += (((T[temp])*i)%mod *kotobar)%mod;
             ans%=mod;
        }
    }
    cout << ans << endl;

    return 0;
}
