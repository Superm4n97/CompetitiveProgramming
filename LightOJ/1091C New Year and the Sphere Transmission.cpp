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

using namespace std;

map < ll , ll > mp;
vector < ll > di , v;

ll fun(ll n,ll d)
{
    return (n*(2+(n-1)*d))/2;
}

int main()
{
    ll n;
    cin >> n;
    ll lm = sqrt(n)+2;
    for (ll i=1;i<lm;i++){
        if (n%i==0){
            if (!mp[i]){
                di.pb(i);
                mp[i]++;
            }
            ll t = n/i;
            if (!mp[t]){
                di.pb(t);
                mp[t]++;
            }
        }
    }
    mp.clear();
    for (int i=0;i<di.size();i++){
        ll tut = fun(di[i],n/di[i]);
        if (!mp[tut]){
            mp[tut]++;
            v.pb(tut);
        }
    }
    srt(v);
    for (int i=0;i<v.size();i++)cout << v[i] <<" ";
    cout << endl;


    return 0;
}
