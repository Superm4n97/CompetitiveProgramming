#include <bits/stdc++.h>
#define pb           push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define maxn            2004
#define mod             1000000007

using namespace std;

vector < char> B;
vector < ll > v;
map < char , ll > mp;
ll n,k;

int main()
{
    ll n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    for (int i=0;i<n;i++){
        mp[s[i]]++;
        if (mp[s[i]]==1){
            B.pb(s[i]);
        }
    }
    for (int i=0;i<B.size();i++){
        v.pb(mp[B[i]]);
    }
    rsrt(v);
    ll un = 0 , cnt = 0;

    for (int i=0;i<k;i++){
        cnt+=v[i];
    }

    cout << n - cnt << endl;

    return 0;
}



