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

ll bigmod(ll a, ll p , ll mod)
{
    if (p==1)return a%mod;

    ll temp = bigmod(a,p/2,mod);
    temp*=temp;
    temp%=mod;
    if (p%2){
        temp = (temp*(a%mod))%mod;
    }
    return temp;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    vll v;
    inputll(v,n);
    srt(v);
    ll ans = 1;

    for (int i=1;i<n;i++){
        ll tut = (i * (n-i));
        ll dis = (v[i]-v[i-1])%m;

        show(tut);
        show(dis);

        tut = bigmod(dis,tut,10000000);
        //tut*=dis;
        //tut%m;
        ans+=tut;
        //ans%=m;
    }
    cout << ans << endl;



    return 0;
}
