#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define mkp(a,b) make_pair(a,b)
#define scf2(a,b) scanf("%lld%lld",&a,&b)
#define scf(a) scanf("%lld",&a)
#define pf(a) printf("%lld\n",a)
#define mx 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[mx][4];
ll b[mx];
ll c[mx],sum=0,ans=0,n;

ll dp[mx][4];

ll rec(ll i , ll bol)
{
    if (dp[i][bol] != -1)return dp[i][bol];
    if (i==n-1)return dp[i][bol] = A[i][bol];

    ll a = (bol+1)%3 , b = (bol+2)%3;
    return dp[i][bol] = max(rec(i+1,a),rec(i+1,b))+A[i][bol];

}

int main()
{
    cin >> n;
    for(ll i=0;i<n;i++)cin >> A[i][0]  >> A[i][1] >> A[i][2];

    memset(dp,-1,sizeof(dp));
    cout << max(rec(0LL,0LL) , max(rec(0LL,1LL) , rec(0LL , 2LL))) << endl;
}
