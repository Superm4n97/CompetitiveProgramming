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

vll v;
ll n;
map < ll , bool > mp;
map < ll , ll > index;
bool solution = false;

void cheack(ll d)
{
    ll one = 1 , cnt = 0;
    for (int i=0 ; i<n ; i++){
        if (mp[v[i]-d] || mp[v[i]+d])cnt++;
        else {
            one = index[v[i]];

           // cout << "  d  " << d << "    v[i] " << index[v[i]] << endl;
        }
    }
   // cout << cnt << endl;
    if (cnt >= n-1 && !solution){
        cout << one << endl;
        solution = true;
    }
}

int main()
{

    scl(n);

    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        v.pb(a);
        mp[a] = true;
        index[a] = i+1;
    }
    if (n==2){
        cout << 1 << endl;
        return 0;
    }
    srt(v);
    cheack(v[1]-v[0]);
    cheack(v[2]-v[0]);
    cheack(v[2]-v[1]);
    if (!solution){
        cout << -1 << endl;
    }

    return 0;
}
