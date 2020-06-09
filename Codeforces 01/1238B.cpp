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

using namespace std;

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll n,r;
        scll(n,r);
        vll v , vv;
        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            v.pb(a);
        }
        rsrt(v);
        vv.pb(v[0]);
        for (int i=1;i<n;i++){
            if(v[i]!=v[i-1])vv.pb(v[i]);
        }
        ll temp = 0 , ans = 0;
        for (int i=0;i<vv.size();i++){
            vv[i]-=temp;
            if (vv[i]>0){
                ans++;
            }
            temp+=r;
        }
        printf("%I64d\n",ans);
    }



    return 0;
}
