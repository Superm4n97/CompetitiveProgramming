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

ll n , mx = 0;
vll v;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.pb(a);
        mx  = max(a,mx);
    }
    ll x = mx, y=0 , z=0;
    for (int i=0;i<n;i++){
        z = __gcd(z,(mx-v[i]));
    }
    for (int i=0;i<n;i++){
        if (z!=0){
            y+=((mx-v[i])/z);
        }
    }
    cout << y << " " << z << endl;




    return 0;
}
