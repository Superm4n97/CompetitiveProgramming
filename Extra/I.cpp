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

ll dp[1003][1003];
ll a,b , dx[] = {-1,0,-1,-2} , dy[] ={0,-2,-1,-2};

bool valid(ll x, ll y)
{
    if (x>a || y>b || x<0 || y<0)return false;
    return true;
}

ll F(ll x, ll y)
{
    if (!valid(x,y)) return 0;
    if (dp[x][y] != -1)return dp[x][y];

    ll temp = 0;
    for (int i=0;i<4;i++){
        temp+=F(x+dx[i] , y+dy[i]);
        temp%=mod;
    }
    return dp[x][y] = temp;
}

int main()
{
    for (int i=0;i<=1002;i++){
        for (int j=0;j<=1002;j++)dp[i][j] = -1;
    }
    dp[0][0] = 1;
    while(scanf("%d %d",&a,&b)!=EOF){
        printf("%lld\n",F(a,b));
//        for (int i=0;i<=a;i++){
//            for (int j=0;j<=b;j++)cout << dp[i][j] << " ";
//            cout << endl;
//        }
    }

    return 0;
}
