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

#define maxn            200005

using namespace std;

ll n;
map < ll , ll > mp , lock1;
map < ll , ll > mp2, lock2;
vll v;

int main()
{
    cin  >> n;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        v.pb(a);
    }
    srt(v);
    vll v2 = v;

    for (int i=0;i<n;i++){
        if (lock1[v[i]]==0){
            if (mp[v[i]-1]==1){
                v[i]--;
            }
            else {
                v[i]++;
                lock1[v[i]] = 1;
                mp[v[i]]=1;
            }
        }
    }

//    for (int i=0;i<n;i++)show(v[i]);

    for (int i=0;i<n;i++){
        if (mp2[v2[i]-1]==0){
            v2[i]--;
            mp2[v2[i]]=1;
        }
        else if (mp2[v2[i]]==0) {
            mp2[v2[i]] = 1;
        }
        else {
            v2[i]++;
            mp2[v2[i]] = 1;
        }
    }
    ll mx = 1 , mn = 1;
    for (int i=1;i<n;i++){
        if (v[i]!=v[i-1])mn++;
        if (v2[i]!=v2[i-1])mx++;
    }
    cout << mn << " " << mx << endl;


    return 0;
}

