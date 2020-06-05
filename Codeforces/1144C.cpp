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
    ll n;
    cin >> n;
    vector < ll > v;
    inputll(v,n);
    srt(v);
    bool ans = true;
    map < ll , ll > mp;

    for (int i=0;i<n;i++){
        mp[v[i]]++;
        if (mp[v[i]]>2)ans = false;
    }
    if (!ans){
        cout << "NO" << endl;
        return 0;
    }

    vector < ll > aa, bb;
    aa.pb(v[0]);
    for (int i=1;i<n;i++){
        if(v[i]==v[i-1])bb.pb(v[i]);
        else aa.pb(v[i]);
    }
    cout << "YES" << endl;
    cout << aa.size() << endl;
    for (int i=0;i<aa.size();i++){
        cout << aa[i] << " ";
    }
    cout << endl;
    cout << bb.size() << endl;
    for (int i=bb.size()-1;i>=0;i--)cout << bb[i] << " ";


    return 0;
}
