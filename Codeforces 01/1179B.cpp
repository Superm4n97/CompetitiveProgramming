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

vector < pll >  v1,v2;
map < pll , ll > mp;

int main()
{
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)v1.pb({i,j});
    }
    srt(v1) , rsrt(v2);
    int i = 0 , j = v1.size()-1;
    while(i<=j){
        if (i==j)printf("%I64d %I64d\n",v1[i].first,v1[i].second);
        else printf("%I64d %I64d\n%I64d %I64d\n",v1[i].first,v1[i].second,v1[j].first,v1[j].second);

        i++ , j--;
    }

    return 0;
}
