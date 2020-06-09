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

vll v,v1,v2;

int main()
{
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        if (i%2){
            v1.pb(i*2-1);
            v2.pb(i*2);
        }
        else {
            v2.pb(i*2-1);
            v1.pb(i*2);
        }
    }
    //cout << (2*n * (2*n+1)/2) << endl;
    if (n%2 == 0){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i=0;i<n;i++)cout << v1[i] << " ";
        for (int i=0;i<n;i++)cout << v2[i] << " ";
    }

    return 0;
}
