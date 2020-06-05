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
#define inf8            100000000009

#define maxn            100005

using namespace std;

int main()
{
    ll n , m;
    cin >> n >> m;
    vll A,B , C , mark;
    map < ll , ll > mp;
    inputll(A,n);
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        B.pb(a);
        if (mp[a]==0){
            mp[a]++;
            mark.pb(a);
        }
    }
    srt(A);
    srt(B);
    if (A==B){
        cout << 0 << endl;
        return 0;
    }
    ll mx = inf8;
    for (int i=0;i<mark.size();i++){
        ll temp = mark[i];
        vll T;

        ll tut = temp - A[0];
        if (tut<0)tut+=m;

        for (int j=0;j<n;j++){
            T.pb((A[j]+tut)%m);
        }
        srt(T);
        if (T==B)mx = min(mx,tut);
    }
    cout << mx << endl;

    return 0;
}
