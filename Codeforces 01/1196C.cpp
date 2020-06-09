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
#define inf8            100000

using namespace std;

int main()
{
    ll tc;
    scl(tc);

    while(tc--){
        ll n , LL = -inf8 , RR = inf8 , UU = inf8 , DD = -inf8;
        scl(n);
        for (int i=0;i<n;i++){
            ll x,y,a,b,c,d;
            scll(x,y);
            scll(a,b);
            scll(c,d);

            ll L = x-a , U = y+b , R = x+c , D = y-d;
            if (a==0)LL = max(LL,x);
            if (c==0)RR = min(RR,x);
            if (d==0)DD = max(DD,y);
            if (b==0)UU = min(UU,y);
        }
        if (RR<LL || UU<DD)cout << 0 << endl;
        else cout << 1 << " " << LL  << " " << UU << endl;
    }

    return 0;
}
