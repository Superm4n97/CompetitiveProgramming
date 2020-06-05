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
    vector < int > vv;
    int n,m;
    cin >>  n >> m;
    for (int i=0;i<n;i++){
        int a;
        scd(a);
        vv.pb(a);
    }
    int b = 0 , e = 300005, ans = 1000000;
    while(b<=e){
        int x = (b+e)/2;
        bool temp = true;

        vector < int > v = vv;
        if (x+v[0] >= m)v[0] = 0;

        for (int i=1;i<n;i++){
            if (v[i] < v[i-1] && v[i]+x >= v[i-1]) v[i] = v[i-1];
            if (v[i]+x > v[i-1] && v[i]+x >= v[i-1]+m) v[i] = v[i-1];
            if (v[i]<v[i-1])temp = false;
        }

        if (temp){
            e = x-1;
            ans = min(ans,x);
        }
        else b = x+1;
    }
    cout << ans << endl;

    return 0;
}
