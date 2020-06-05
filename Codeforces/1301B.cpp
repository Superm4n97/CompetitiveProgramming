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
        ll n;
        cin >> n;
        vll v;
        ll A[n+5];
        A[0] = A[n+1] = 0;

        for (int i=1;i<=n;i++)cin >> A[i];

        for (int i=1;i<=n;i++){
            if (A[i]>=0 && (A[i+1]==-1 || A[i-1]==-1)){
                v.pb(A[i]);
            }
//            if (A[i]>=0){
//                v.pb(A[i]);
//            }
        }
        srt(v);
        if (v.empty()){
            cout << "0 0" << endl;
            continue;
        }
        if (v.size() <= 1){
            cout << "0 " << v[0] << endl;
            continue;
        }
        ll m = v.size();
        ll k = (v[m-1] + v[0]) / 2;

        for (int i=1;i<=n;i++){
            if (A[i] == -1){
                A[i] = k;
            }
        }
        ll ans = 0;
        for (int i=1;i<n;i++){
            ans = max(ans , abs(A[i]-A[i+1]));
        }

        cout << ans << " " << k << endl;
    }


    return 0;
}
