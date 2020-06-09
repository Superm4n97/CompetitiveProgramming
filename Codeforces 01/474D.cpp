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
#define mod             1000000007

using namespace std;

ll q, k;
ll dp[100005],cusum[100005];

int main()
{
    cin >> q >> k;
    dp[0]=1,cusum[0]=1;
    for (ll i=1;i<100005;i++){
        dp[i] = 0 , cusum[i] = 0;

        if (i<k)dp[i]=1,cusum[i] = cusum[i-1]+1;
        else {
            dp[i] = ((dp[i-1] + dp[i-k])%mod);
            cusum[i] = ((dp[i]+cusum[i-1])%mod);
        }
    }
    for (ll i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        ll ans = cusum[b]-cusum[a-1];
        if (ans<0)ans+=mod;
        cout << ans << endl;
    }

    return 0;
}
