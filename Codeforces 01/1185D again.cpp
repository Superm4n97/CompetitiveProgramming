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

ll n , x = 0;
vll v;
map < ll , ll > mp;

void funny(ll d)
{
    if (x)return;

    ll cnt = 0 , index = 1;
    for (int i=0;i<n;i++){
        if (i==0){
            if (v[1]-v[0] != d && v[2]-v[0]!=d){
                cnt++;
                index = 1;
            }
        }
        if (i==n-1){
            if (v[i]-v[i-1] != d && v[i]-v[])
        }

    }
}

int main()
{
    scl(n);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        mp[a] = i+1;
        v.pb(a);
    }
    if (i<=3){
        cout << 1 << endl;
    }
    else {
        srt(v);

    }

    return 0;
}
