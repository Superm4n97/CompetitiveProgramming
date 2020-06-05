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

map < int , int > mp;
int cnt[100005];

int main()
{
    int n ,ans = 0, mx = 0;
    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[mp[a]]--;
        mp[a]++;
        cnt[mp[a]]++;
        mx = max(mx,mp[a]);

        if (mx==i || (mx==1) || (cnt[mx]*mx==i-1) || (cnt[mx-1]*(mx-1)+(mx-1)==i-1))ans = i;
        //cout << "i " << i << "    mx " << mx << "    ans " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
