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
#define maxn            300003
#define inf             1000000000000000004

using namespace std;

ll A[maxn], B[maxn] , n;
ll dp[maxn][4];

ll fntion(ll pos , ll pls)
{
    if (pos==n){
        return dp[pos][pls] = pls*B[pos];
    }
    if (dp[pos][pls]!=-1)return dp[pos][pls];

    ll ret = inf;

    for (int i=0;i<3;i++){
        if (A[pos]+pls != A[pos+1]+i){
            ret = min(ret,fntion(pos+1,i));
        }
    }
    return dp[pos][pls] = ret+ B[pos]*pls ;
}

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll ans = inf;
        scl(n);
        for (int i=1;i<=n;i++){
            scll(A[i],B[i]);
            dp[i][0] = 0;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }

        for (int i=0;i<3;i++){
            ans = min(ans,fntion(1,i));
        }

        printf(" %I64d\n",ans);
    }


    return 0;
}
