#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k;
ll dp[203][202][203];
ll two[205] , five[203] , ans = 0;

ll recursion(ll pos , ll numberOfFive , ll kLeft)
{
    if (pos>n)return 0;
    if (dp[pos][numberOfFive][kLeft] != -1)return dp[pos][numberOfFive][kLeft];
    if (kLeft>k)return 0;

    ll p = recursion(pos+1 , numberOfFive , kLeft);
    ll q = recursion(pos+1 , numberOfFive+five[pos] , kLeft+1) + two[pos];

    if (q>p) p = q;

    return dp[pos][numberOfFive][kLeft] = p;
}


int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        ll a , t = 0 , f = 0;
        cin >> a;
        while(a%5==0){
            f++;
            a/=5;
        }
        while(a%2==0){
            t++;
            a/=2;
        }
        five[i] = f , two[i] = t;
    }
    recursion(1,0,0);

    for (ll i=1;i<202 ; i++){
        for (ll j = 1; j <202;j++){
            for (ll l=1 ; l<202 ; l++){
                ans = max(ans,min(dp[i][j][l],j));
            }
        }
    }
    cout << ans << endl;


    return 0;
}
