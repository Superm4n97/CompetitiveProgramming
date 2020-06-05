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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair

using namespace std;

map < pll ,int > mp;
ll x[2005],y[2005];
vector < pll > v;

int main()
{
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++)cin >> x[i] >> y[i];
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll a = x[i]+x[j];
            ll b = y[i]+y[j];
            mp[mk(a,b)]++;
            if (mp[mk(a,b)]==1)v.pb(mk(a,b));
        }
    }
    int cnt = 0;
    for (int i=0;i<v.size();i++){
        //cout <<"    " << v[i].first << " " << v[i].second << "   " << mp[v[i]] << endl;
        cnt+= mp[v[i]]*(mp[v[i]]-1)/2;
    }
    cout << cnt << endl;

    return 0;
}
