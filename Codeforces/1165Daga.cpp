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

using namespace std;

int main()
{
    int tc;
    scd(tc);
    while(tc--){
        ll n;
        scl(n);
        vll v , vv;
        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            v.pb(a);
        }
        srt(v);
        ll G;
        bool ans = true;
        if (n==1)G = v[0]*v[0];
        else G = v[0]*v[n-1];
        ll  lim = sqrt(G)+1;

        map < ll , ll > mp;
        for (int i=2;i<=lim;i++){
            if (G%i==0){
                mp[i]++;
                if (mp[i]==1)vv.pb(i);
                ll tut = G/i;
                mp[tut]++;
                if (mp[tut]==1)vv.pb(tut);
            }
        }
        srt(vv);
        if (vv==v)cout << G << endl;
        else cout << -1 << endl;
    }

    return 0;
}

