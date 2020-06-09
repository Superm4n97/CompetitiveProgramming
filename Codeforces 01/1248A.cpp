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
#define inf8            100000008

#define maxn            100005

using namespace std;

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll n,m;
        scl(n);
        ll ev1 = 0 , odd1 = 0 , ev2= 0 , odd2= 0;

        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            if (a%2)odd1++;
            else ev1++;
        }
        scl(m);
        for (int i=0;i<m;i++){
            ll a;
            scl(a);
            if (a%2)odd2++;
            else ev2++;
        }
        printf("%I64d\n",ev1*ev2+odd1*odd2);
    }



    return 0;
}
