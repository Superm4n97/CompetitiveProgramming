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

ll dp[2003][2003],n,m;

ll F(ll r, ll c)
{
    if (dp[r][c] != 0)return dp[r][c];
    if (r==m)return dp[r][c] = 1;

    ll temp=0;
    for (int i=1 ; c*i<=n ; i++)temp += F(r+1,c*i) , temp%=mod;
    return dp[r][c] = temp;
}

int main()
{
    cin >> n >> m;
    ll temp=0;
    for (int i=1;i<=n;i++)temp+=F(1,i) , temp%=mod;
    cout << temp << endl;

    return 0;
}
