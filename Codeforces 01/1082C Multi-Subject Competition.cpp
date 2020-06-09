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

using namespace std;

vll v[100005],vsz;
map < pair < ll , ll > , ll > mp;
ll sz[100005],vvz=0;

int main()
{
    ll n,m,ans=0;
    scll(n,m);
    for (int i=0;i<n;i++){
        ll a,b;
        scll(a,b);
        v[a].pb(b);
    }
    for (int i=1;i<=m;i++)rsrt(v[i]),sz[i]=v[i].size(),vvz = max(sz[i],vvz);
    for (int i=1;i<=m;i++){
        if (sz[i]==0)continue;
        mp[mk(i,1)] = v[i][0];
        for (int j=1;j<v[i].size();j++){
            v[i][j] += v[i][j-1];
            mp[mk(i,j+1)] = v[i][j];
        }
    }

    for (int i=1;i<=vvz;i++){
        ll ii = i , temp = 0;
        for (int j=1;j<=m;j++){
            if (sz[j]>=ii && mp[mk(j,ii)]>0)temp+=mp[mk(j,ii)]; ///
        }
        ans = max(ans,temp);
    }
    cout << ans << endl;


    return 0;
}
