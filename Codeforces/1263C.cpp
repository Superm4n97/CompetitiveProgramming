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

#define maxn            100005

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        vll ans;
        map < ll , ll > mp;

        ll n;
        cin >> n;
        ll lim = sqrt(n)+1;
        ans.pb(0);
        mp[0]  =1;

        for (int i = 1;i<=lim ; i++){
            ll a = n/i;
            ll b = 1;
            if (a!=0)b = n/a;
            if (mp[a]==0){
                mp[a]=1;
                ans.pb(a);
            }
            if (mp[b]==0){
                mp[b]=1;
                ans.pb(b);
            }
        }
        srt(ans);
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)cout << ans[i] << " ";
        cout << endl;
    }


    return 0;
}
