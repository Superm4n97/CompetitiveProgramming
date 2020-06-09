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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1003

using namespace std;

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
ll A[maxn][2*maxn];
ll B[maxn][maxn];

bool check(ll x, ll y)
{
    if (x<n && x>=0 && y>=0 && y<n)return true;
    return false;
}

void dfs(ll x, ll y , ll xxx , ll yyy)
{
    for (int i=0;i<4;i++){
        ll xx = x+dx[i] , yy = y+dy[i];
        if (check(xx,yy)){
            if (A[xx][yy*2]==xxx && A[xx][yy*2+1]==yyy && !B[xx][yy]){
                B[xx][yy] = i+1;
                dfs(xx,yy,xxx,yyy);
            }
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<2*n;j++){
            scl(A[i][j]);
        }
    }

    bool ans = true;

    for (int i=0;i<n;i++){
        for (int j = 1;j<n;j++){
            if(!B[i][j]){
                ll x  = A[i][j*2] , y = A[i][j*2+1];
                B[x][y] = 5;
                if (A[x][y*2]!=x || A[x][y*2+1]!=y)ans = false;
                dfs(x,y);
            }
        }
    }



    return 0;
}
