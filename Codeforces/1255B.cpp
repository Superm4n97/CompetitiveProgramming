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
        scll(n,m);

        vector <pll>v , v2;
        ll sum = 0;
        for (int i=1;i<=n;i++){
            ll a;
            scl(a);
            v.pb({a,i});
        }
        if (m<n || n==2){
            cout << -1 << endl;
            continue;
        }
        srt(v);

        for (int i=0;i<n/2;i++){
            v2.pb(v[i]);
            v2.pb(v[n-i-1]);
        }
        if (n%2){
            v2.pb(v[n/2]);
        }
        for (int i=0;i<n;i++){
            if (i==n-1)sum+=(v2[i].first+v[0].first);
            else sum+=(v2[i].first+v2[i+1].first);
        }
        sum+=(v[0].first+v[1].first)*(m-n);
        cout <<sum << endl;
        for (int i=0;i<n;i++){
            if (i==n-1)cout << v2[i].second << " " << v2[0].second << endl;
            else cout << v2[i].second << " " << v2[i+1].second << endl;
        }
        for (int i=0;i<m-n;i++)cout << v[0].second << " " << v[1].second << endl;
    }



    return 0;
}
