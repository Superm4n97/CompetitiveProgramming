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

using namespace std;

ll n,m,A[60][60];
map < pii , int > mp;

bool check(int x, int y)
{
    if (A[x][y] && A[x+1][y] && A[x][y+1] && A[x+1][y+1])return true;
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> A[i][j];
        }
    }
    vector < pii > v;
    bool ans = true;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x = i , y = j;
            if (check(x,y)){
                mp[{x,y}] = 1;
                mp[{x+1,y}] = 1;
                mp[{x,y+1}] = 1;
                mp[{x+1,y+1}] = 1;
                v.pb({x,y});
            }
            if (A[x][y]==1 && mp[{x,y}]==0)ans = false;
        }
    }
    if (!ans){
        cout << -1 << endl;
    }
    else {
        cout << v.size() << endl;
        for (int i=0;i<v.size();i++)cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
