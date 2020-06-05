#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll n,p;
ll DP[1005][1005];

ll poo(ll a)
{
    ll tut=a;
    for (int i=1;i<p;i++)tut*=a;
    return tut;
}

ll funny(ll starting, ll remaning)
{
    if (remaning==0)return 1;
    if (DP[starting][remaning] != -1)return DP[starting][remaning];

    ll tut = 0 , ppp = poo(starting);
    //cout << "starting remaining   " << starting << " " << remaning << " " << ppp << endl;
    if (ppp > remaning)return 0;

    tut+=funny(starting+1 , remaning);
    tut+=funny(starting+1 , remaning-ppp);

    return DP[starting][remaning] = tut;
}

int main()
{
    scll(n,p);
    for (int i=0;i<=n+2;i++){
        for (int j=0;j<=n+2;j++)DP[i][j] = -1;
    }
    cout << funny(1,n) << endl;

    return 0;
}
