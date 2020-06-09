#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll n,m,k;
ll dp[5005][5005];
ll A[5005] , temp =1;

ll recur(ll pos , ll a)
{
    //cout << temp << endl;
    //temp++;
    if (a>k || pos+m-1>n)return 0;
    if (dp[pos][a] != -1)return dp[pos][a];

    //ll ans = 0;
    //for (ll i = pos+m ; i<=n ; i++)ans = max(ans,recur(i,a+1));

    ll res1 = recur(pos+1,a);
    ll res2 = recur(pos+m , a+1) + (A[pos+m-1]-A[pos-1]);

    //return dp[pos][a] = ans+(A[pos+m-1]-A[pos-1]);
    return dp[pos][a] = max(res1,res2);
}

int main()
{
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    for (int i=1;i<=n;i++){
        scanf("%I64d",&A[i]);
        A[i]+=A[i-1];
    }

    memset(dp,-1,sizeof(dp));
    ll ans = recur(1,1);
    //for (ll i=1;i<=n;i++)ans = max(ans,recur(i,1));

    printf("%I64d\n",ans);

    return 0;
}
