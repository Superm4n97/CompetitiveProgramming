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
#define inf8            100000008
#define maxn            100005

using namespace std;

ll n,X[maxn],Y[maxn] , Z[maxn];
ll mark[maxn];
vector < pair < ll , ll > > ans;
vector < pair < pair <ll,ll> , pair<ll,ll> > > vp;

ll recur(ll a)
{
    if (a>=n)return;
    if (a==n-1)return a;
    if (a==n-2){
        v.pb({vp[a].second.second , vp[a+1].second.second});
        return -1;
    }

    ll b = a+1 , c = a+2 , d = -1;
    if(min(vp[a].first.first,vp[b].first.first) <= vp[c].first.first && vp[c].first.first <= max(vp[a].first.first,vp[b].first.first)){
        d =recur(b);
    }
    else if(min(vp[a].first.second,vp[b].first.second) <= vp[c].first.second && vp[c].first.second <= max(vp[a].first.second,vp[b].first.second)){
        d = recur(b);
    }
    else if(min(vp[a].second.first,vp[b].second.first) <= vp[c].second.first && vp[c].second.first <= max(vp[a].second.first,vp[b].second.first)){
        d = recur(b);
    }
    if (d!=-1){
        ans.pb()
    }
}

int main()
{
    scl(n);
    for (int i=1;i<=n;i++){
        scll(X[i],Y[i]);
        scl(Z[i]);
        vp.pb({{X[i],Y[i]},{Z[i],i}});
    }
    srt(vp);

    recur(0);

    for (int i=0;i<n;i++){
        ll a = vp[i].second.second;
        recur(i);

    }



    return 0;
}
