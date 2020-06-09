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
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        vector < pll > v;
        for (int i=0;i<n;i++){
            ll a,b;
            cin >> a >> b;
            v.pb({a,b});
        }
        srt(v);
        bool ans = true;
        for (int i=1;i<n;i++){
            if (v[i].second<v[i-1].second)ans = false;
        }
        if (!ans){
            cout << "NO" << endl;
            continue;
        }
        string s = "";
        ll x = 0 , y = 0;
        for (int i=0;i<n;i++){
            for (int j = x+1 ; j<=v[i].first ; j++)s = s+"R";
            for (int j = y+1 ; j<=v[i].second ; j++)s = s+"U";
            x = v[i].first , y = v[i].second;
        }
        cout << "YES" << endl;
        cout << s << endl;
    }


    return 0;
}
