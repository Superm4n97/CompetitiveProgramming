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
        ll n,t,a,b;
        cin >> n >> t >> a >> b;
        ll A[n+3] , B[n+3];
        vector < pll > v;
        for (int i=0;i<n;i++)cin >>A[i];
        for (int i=0;i<n;i++){
            cin >> B[i];
            ll temp = a;
            if (A[i]==1)temp = b;
            v.pb({B[i] , temp});
        }
        srt(v);
        ll csum[n+5];
        memset(csum,0,sizeof(csum));
        csum[0] = v[0].second;
        for (int i=1;i<n;i++){
            csum[i] = csum[i-1]+v[i].second;
        }
        ll ans = 0;
        for (int i=0;i<n;i++){
                if (csum[i]<v[i].first)ans = i+1;
            if (csum[i]<=t){
                if (i==n-1)ans = n;
                else if (csum[i]<v[i+1].second){
                    ans = i+1;
                }
            }
        }
        cout << ans << endl;
    }



    return 0;
}
