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
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll n,k,w,ans;
vector < ll > v;
ll dp[102][102];

ll brush(ll x, ll rest, ll pre)
{
    //cout << "     " << x << endl;
    if (dp[x][rest] != -1)return dp[x][rest];
    if (x==n || rest==-1)return 0;
    if (abs(pre-v[x]) <= w)return brush(x+1,rest,pre)+1;

    return dp[x][rest] = max(brush(x+1,rest-1,v[x])+1,brush(x+1,rest,pre));
    //ans = max(ans,dp[x][rest]);
   // return dp[x][rest];
}

int main()
{
    int tc;
    scd(tc);

    for (int _t=1;_t<=tc;_t++){
        scll(n,w),scl(k);

        v.clear();
        ans=0;
        for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++)dp[i][j] = -1;
        }

        for (int i=0;i<n;i++){
            ll a,b;
            scll(a,b);
            v.pb(b);
        }
        srt(v);

        ll temp = brush(0,k,-1000000000000);
        printf("Case %d: %lld\n",_t,temp);
    }

    return 0;
}
