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
#define inf8            100000008          100000008

using namespace std;

ll A[1002][1002] , B[1002][1002] , n , m;
vector < pair < char , pair < ll , ll > > > vp;

int main()
{
    ll n,d,k;
    cin >> n >> d >> k;
    map < ll , string > mp;
    vector < pll > v;

    for (int i=0;i<n;i++){
        string s;
        ll a;
        cin >> s >> a;
        mp[i] = s;
        v.pb({a,i});
    }
    rsrt(v);
    vll ansVector;
    bool ans = false;
    ll sum = 0;
    for (int i=0;i<k;i++){
        sum+=v[i].first;
    }
    if (sum<d)cout << "impossible" << endl;
    else {
            cout << k << endl;
        for (int i=0;i<k;i++){
            cout << mp[v[i].second] << ", YOU ARE FIRED!" << endl;
        }
    }

    return 0;
}
