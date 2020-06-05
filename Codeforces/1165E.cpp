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

ll A[200005] , T[300005] , ans = 0;

ll seg(ll b, ll e, ll node)
{
    if (b==e){
        ans+=A[b];
        ans%=mod;
        return T[node]  = A[b];
    }

    ll mid = (b+e)/2;
    ll t1 = seg(b,mid,node*2);
    ll t2 = seg(mid+1,e,node*2+1);
    t1+=t2;
    t1%=mod;
    ans+=t1;
    ans%=mod;
    return T[node] = t1;
}

int main()
{
    ll n;
    cin >> n;
    vll v , vv;
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        v.pb(a);
    }
    srt(v);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        vv.pb(a);
    }
    rsrt(vv);
    for (int i=1;i<=n;i++){
        A[i] = (v[i-1]*vv[i-1])%mod;
    }
    //seg(1,n,1);

    cout << ans << endl;

    return 0;
}

