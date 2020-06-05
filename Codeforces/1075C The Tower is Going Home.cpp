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
#define mk              make_pair
#define MX              1e9+7

using namespace std;

int main()
{
    map < ll , ll> bar,mp,mark;
    vector < ll > v,v_ans;
    ll n,m;
    scl(n),scl(m);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        v.pb(a);
        bar[a]=1;
        mark[a]=1;
    }
    bar[1000000000]=1;
    for (int i=0;i<m;i++){
        ll x1,x2,y;
        scl(x1),scl(x2),scl(y);
        if (!mark[x1]){
            v.pb(x1);
            mark[x1]++;
        }
        if (!mark[x2+1]){
            v.pb(x2+1);
            mark[x2+1]++;
        }
        mp[x1]++,mp[x2+1]--;
    }
    if (!mark[1])v.pb(1);
    v.pb(1000000000);
    srt(v);

//    cout << "v vector " << endl;
//    for (int i=0;i<v.size();i++)cout << v[i] << " ";
//    cout << endl;

    for (int i=1;i<v.size();i++)mp[v[i]]+=mp[v[i-1]];
    ll mn = MX;
    for (int i=0;i<v.size();i++){
        mn = min(mn,mp[v[i]]);
        if (bar[v[i]]){
            v_ans.pb(mn);
            //cout << "for " << v[i] << " mn " << mn << endl;
            mn = MX;
        }
    }

//    cout << "v_ans vector " << endl;
//    for (int i=0;i<v_ans.size();i++)cout << v_ans[i] << " ";
//    cout << endl;

    mn = MX;
    for (int i=0;i<v_ans.size();i++){
        v_ans[i]+=i;
        mn = min(mn,v_ans[i]);
    }

    cout << mn << endl;

    return 0;
}
