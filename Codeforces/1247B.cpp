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
    scl(tc);
    while(tc--){
        ll n, k,d;
        scll(n,k);
        scl(d);

        ll A[n+4];
        for (int i=1;i<=n;i++)scl(A[i]);
        map < ll , ll > mp;
        ll cnt = 0;
        for (int i=1;i<=d;i++){
            mp[A[i]]++;
            if (mp[A[i]]==1)cnt++;
        }
        //cout << "temp 1" << endl;
        ll ans = cnt;
        //show(cnt);

        ll b = 2 , e = d+1;
        while(e<=n){
            mp[A[b-1]]--;
            if (mp[A[b-1]]==0)cnt--;
            mp[A[e]]++;
            if (mp[A[e]]==1)cnt++;

            //show(cnt);

            ans = min(ans,cnt);
            b++,e++;
        }
        cout << ans << endl;
    }



    return 0;
}
