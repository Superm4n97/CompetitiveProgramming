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
#define inf             100000000000000004

using namespace std;

ll A[maxn][4], B[maxn] , n;
ll dp[maxn][4];


int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll ans = inf;
        scl(n);
        for (int i=1;i<=n;i++){
            scll(A[i][0],B[i]);
            dp[i][0] = 0;
            dp[i][1] = B[i];
            dp[i][2] = B[i]*2;
            A[i][1] = A[i][0]+1;
            A[i][2] = A[i][0]+2;
        }
        for (int i=2;i<=n;i++){
            for (int j=0;j<3;j++){
                ll a = A[i][j] , mn = inf;
                for (int k=0;k<3;k++){
                    ll b = A[i-1][k];
                    if (a==b)continue;

                    mn = min(dp[i-1][k], mn);
                }
                dp[i][j] += mn;
            }
        }
//        for (int i=1;i<=n;i++){
//            for (int j=0;j<3;j++)cout << dp[i][j] << " ";
//            cout << endl;
//        }
        for (int i=0;i<3;i++)ans = min(ans,dp[n][i]);
        cout << ans << endl;



        //printf(" %I64d\n",ans);
    }


    return 0;
}
