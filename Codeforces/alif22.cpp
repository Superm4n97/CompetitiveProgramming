#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 105
#define MX 1000000000000000005
#include <bits/stdc++.h>
using namespace std;

ll dp[300005][5];
vector<ll> cost, H;
int n;

ll rec(int pos, int st){
    if(dp[pos][st] != -1) return dp[pos][st];
    if(pos == n){
        return 0;
    }
    ll res1, res2, res3;
    res1 = res2 = res3 = MX;
    ll x = H[pos] + st;
    if(x != H[pos + 1]){
        res1 = rec(pos+1, 0);
    }
    if(x != H[pos + 1]+1){
        res2 = cost[pos+1] + rec(pos+1, 1);
    }
    if(x != H[pos + 1]+2){
        res3 = cost[pos+1] + cost[pos+1] + rec(pos+1, 2);
    }
    return dp[pos][st] = min(res1, min(res2, res3));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cost.clear();
        H.clear();
        cin >> n;
        for(int i=0;i<=n+5;i++){
            for(int j=0;j<=2;j++){
                dp[i][j] = -1;
            }
        }
        for(int i=0;i<n;i++){
            ll x, y;
            cin >> x >> y;
            H.pb(x);
            cost.pb(y);
        }
        H.pb(0);
        cost.pb(0);
        ll ans = MX;
        ans = min(ans, rec(0, 0));
        ans = min(ans, cost[0] + rec(0, 1));
        ans = min(ans, cost[0] + cost[0] + rec(0, 2));
        cout << ans << endl;

    }


}

