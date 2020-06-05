#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair
#define inf8            100000008
#define mod             998244353

using namespace std;

int main()
{
    vll A,B;
    ll n;
    scl(n);
    for (int i=1;i<=n;i++){
        ll a;
        scl(a);
        A.pb(a*(i*(n-i+1)));
    }
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        B.pb(a);
    }
    rsrt(A) , srt(B);
    ll ans = 0;
    for (int i=0;i<n;i++){
        A[i]%=mod;
        ll temp = A[i]*B[i];
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    cout << ans << endl;

    return 0;
}
