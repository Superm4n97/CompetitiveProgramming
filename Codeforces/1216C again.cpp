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

ll x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,dx1,dx2,dy1,dy2,dx3,dy3;

int main()
{
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cin >> x5 >> y5;
    cin >> x6 >> y6;

    dx1 = min(x2,x4) - max(x1,x3);
    dy1 = min(y2,y4) - max(y1,y3);

    dx2 = min(x2,x6) - max(x1,x5);
    dy2 = min(y2,y6) - max(y1,y5);

    dx3 = min(x6,x4) - max(x5,x3);
    dy3 = min(y6,y4) - max(y5,y3);

    if (dx1<0)dx1 = 0;
    if (dx2<0)dx2 = 0;
    if (dx3<0)dx3 = 0;
    if (dy1<0)dy1 = 0;
    if (dy2<0)dy2 = 0;
    if (dy3<0)dy3 = 0;

    ll cover = dx1*dy1 +



    return 0;
}
