#include<bits/stdc++.h>

#define ll long long int

using namespace std;

ll n,k , ans = 0;
ll F[205],T[205];
ll dp[203][203][203];

ll rec(ll pos , ll five , ll remK)
{
    if (remK == 0)return 0;
    if (pos>n)return 0;
    if (dp[pos][five][remK] != -1)return dp[pos][five][remK];

    ll fv = five;

    ll t1 = rec(pos+1 , five , remK);
    ll t2 = rec(pos+1 , five+F[pos] , remK-1) + T[pos];
    dp[pos][five][remK] = max(t1,t2);
    if (t2>=t1){
        fv += F[pos];
    }
    ans = max(ans , min(fv,dp[pos][five][remK]));
    cout << "pos:" << pos << "  five:" << five <<

    return dp[pos][five][remK];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;

        while(a%2==0){
            T[i]++;
            a/=2;
        }
        while(a%5==0){
            F[i]++;
            a/=5;
        }
    }
    ll temp = rec(1,0,k);
    cout << ans << endl;

    return 0;
}
