#include <bits/stdc++.h>
#define pb              push_back
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
#define printCaseAnsInt(t,ans)  printf("Case %d: %d\n",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld\n",t,ans)

using namespace std;

ll A[15][15];
ll n,m;
vll v;

ll DP(ll a , ll level)
{
    if (level == m-1)return A[a][level] = 1;
    if (A[a][level] != -1)return A[a][level];

    ll retValue = 0;
    for (int i=0;i<v.size();i++){
        if (abs(v[i]-a)<3){
            retValue += DP(v[i] , level+1);
        }
    }
    return A[a][level] = retValue;
}

int main()
{
    ll tc;
    scl(tc);
    for (ll _t=1;_t<=tc;_t++){
        scll(n,m);
        for (int i=0;i<15;i++){
            for (int j=0;j<15;j++)A[i][j] = -1;
        }
        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            v.pb(a);
        }
        ll ans = 0;
        for (int i=0;i<v.size();i++){
            ans+=DP(v[i] , 0);
        }
        printCaseAnsLL(_t,ans);

        v.clear();
    }

    return 0;
}
