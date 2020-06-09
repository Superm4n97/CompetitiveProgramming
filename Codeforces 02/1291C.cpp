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
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n,m,k;
        cin >> n >> m >> k;
        ll A[n+5];
        for (int i=0;i<n;i++)cin >> A[i];

        ll iCanChose = min(k,m-1) ;
        ll theyCanChose = max(m-1-iCanChose,0LL);

        ll ans = -1;

        for (int i=0;i<=iCanChose;i++){
            ll L = i , R = i + (n  - iCanChose - 1);
            ll seg = n  - iCanChose - theyCanChose-1;

            ll mn = inf;

            //show(L);
            //show(R);

            for (int j=0 ; j<=theyCanChose;j++){
                ll LL = j+L ;
                ll RR = LL+seg;

                ll temp = max(A[LL],A[RR]);
                mn = min(mn,temp);
            }
            ans  = max(ans,mn);
        }
        cout << ans << endl;

    }


    return 0;
}
