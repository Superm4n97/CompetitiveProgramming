#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll A[18][18], DP[18][18][65540] ,n;

ll MarCere(ll x, ll y, ll mask)
{
    ll temp = (1 << y);
    if ((mask & temp) != 0)return 0;
    mask = mask|temp;
    if (DP[x][y][mask]!=-1)return DP[x][y][mask];
    if (x==n-1)return DP[x][y][mask] = A[x][y];
    ll mx = 0;

    for (ll i=0;i<n;i++){
        mx = max(mx,MarCere(x+1,i,mask));
    }
    return DP[x][y][mask] = mx+A[x][y];
}

ll Arr[200];

int main()
{
    ll tc;
    scl(tc);
    for (ll _t=1;_t<=tc;_t++){
        scl(n);
        for (ll i=0;i<n;i++){
            for (ll j=0;j<n;j++){
                for (ll k=0;k<65540;k++)DP[i][j][k]=-1;
            }
        }
        for (ll i=0;i<n;i++){
            for (ll j=0;j<n;j++)scl(A[i][j]);
        }

        ll mx=0;
        for (ll i=0;i<n;i++){
            mx = max(mx,MarCere(0,i,0));
        }

        //printf("Case %lld: %lld\n",_t,mx);
        Arr[_t] = mx;
    }

    for (ll _t=1;_t<=tc;_t++)
        printf("Case %lld: %lld\n",_t,Arr[_t]);

    return 0;
}
