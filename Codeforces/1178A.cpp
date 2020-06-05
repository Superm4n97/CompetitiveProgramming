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

vll ans ,  vv, v;

int main()
{
    ll n;
    scl(n);
    ll total = 0 , alice = 0 , tut = 0;

    for (int i=0;i<n;i++){
        ll a;
        scl(a);

        if (i==0){
            alice = a;
            tut = a;
            total = a;
            ans.pb(a);
        }
        else {
            v.pb(a);
            total += a;
        }
    }
    vv = v;
    rsrt(v);
    map < ll , ll > mp;

    for (int i=0;i<v.size();i++){
        if (alice>total/2)break;

        if (tut >= v[i]*2){
            ans.pb(v[i]);
            alice+=v[i];
            mp[v[i]]++;
        }
    }
    if (alice>total/2){
        cout << ans.size() << endl;
        cout << 1 << " ";
        for (int i=0;i<vv.size();i++){
            if (mp[vv[i]]){
                cout << i+2 << " ";
                mp[vv[i]]--;
            }
        }
        cout << endl;
    }

    else {
        cout << 0 << endl;
    }

    return 0;
}
