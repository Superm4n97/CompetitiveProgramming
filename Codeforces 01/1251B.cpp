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

ll n;
string G[53];

int main()
{
    ll tc;
    scl(tc);

    while(tc--){
        scl(n);
        ll ans = 0 , stable = 0 , unstable = 0;
        for (int i=1;i<=n;i++){
            string s;
            cin >> s;
            ll one = 0 , zero = 0;
            for (int i=0;i<s.size();i++){
                if (s[i]=='0')zero++;
                else one++;
            }
            if (one%2==0 && zero%2==0)ans++;
            else if (one%2==1 && zero%2==1)unstable++;
            else stable++;
        }
        ans+=(unstable);
        if (unstable%2){
            unstable = 1;
            ans--;
        }
        else unstable = 0;
        ll tut = min(stable,unstable);
        ans+=tut*2;
        ans+=(stable-tut);
        cout << ans << endl;
    }



    return 0;
}
